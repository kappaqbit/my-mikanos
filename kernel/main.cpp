#include <cstdint>
#include "frame_buffer_config.hpp"

struct PixelColor {
    uint8_t r, g, b;
};

int WritePixel(
    const FrameBufferConfig& config,
    int x,
    int y,
    const PixelColor& c
) {
    const int pixel_positon = config.pixels_per_scan_line * y + x;
    if (config.pixel_format == kPixelRGBResv8BitPerColor) {
        uint8_t* p = &config.frame_buffer[4 * pixel_positon];
        p[0] = c.r;
        p[1] = c.g;
        p[2] = c.b;
    } else if (config.pixel_format == kPixelBGRResv8BitPerColor) {
        uint8_t* p = &config.frame_buffer[4 * pixel_positon];
        p[0] = c.b;
        p[1] = c.g;
        p[2] = c.r;
    } else {
        return -1;
    }
    return 0;
}

extern "C" void KernelMain(const FrameBufferConfig& frame_buffer_config) {
    for (int x = 0; x < frame_buffer_config.horizontal_resolution; ++x) {
        for (int y = 0; y < frame_buffer_config.vertical_resolution; ++y) {
            WritePixel(frame_buffer_config, x, y, {255, 255, 255});
        }
    }
    for (int x = 0; x < 200; ++x) {
        for (int y = 0; y < 200; ++y) {
            WritePixel(frame_buffer_config, 100 + x, 100 + y, {15,128,15});
        }
    }
    for (int x = 0; x < 50; ++x) {
        for (int y = 0; y < 50; ++y) {
            WritePixel(frame_buffer_config, 125 + x, 150 + y, {0, 0, 0});
        }
    }
    for (int x = 0; x < 50; ++x) {
        for (int y = 0; y < 50; ++y) {
            WritePixel(frame_buffer_config, 225 + x, 150 + y, {0, 0, 0});
        }
    }
    for (int x = 0; x < 50; ++x) {
        for (int y = 0; y < 75; ++y) {
            WritePixel(frame_buffer_config, 175 + x, 200 + y, {0, 0, 0});
        }
    }
    for (int x = 0; x < 25; ++x) {
        for (int y = 0; y < 75; ++y) {
            WritePixel(frame_buffer_config, 150 + x, 225 + y, {0, 0, 0});
        }
    }
    for (int x = 0; x < 25; ++x) {
        for (int y = 0; y < 75; ++y) {
            WritePixel(frame_buffer_config, 225 + x, 225 + y, {0, 0, 0});
        }
    }

    while (1) __asm__("hlt");
}
