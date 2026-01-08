#pragma once

extern "C" {
  void IoOut32(unsigned short addr, unsigned int data);
  unsigned int IoIn32(unsigned short addr);
}
