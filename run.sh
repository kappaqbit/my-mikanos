#!/bin/bash

cp /home/kappaq168/edk2/Build/MikanLoaderX64/DEBUG_CLANG38/X64/Loader.efi BOOTX64.EFI
/home/kappaq168/osbook/devenv/run_qemu.sh BOOTX64.EFI $*
