# Firmware

The firmware lives in the [`firmware` folder](https://github.com/AndrewCromar/stepminia/tree/main/firmware)
of the repo, and there will likely be a compiled (UF2) build there too.

!!! note "Work in progress"
    Flashing instructions haven't been written yet.

Rough flow (to be expanded):

1. Put the Waveshare RP2040 Zero into bootloader mode (hold BOOT, tap RESET).
2. Drag the compiled `.uf2` onto the drive that appears.
3. The board reboots running Stepminia firmware.

!!! info "Planned"
    Firmware V2 is on the roadmap — including button debounce.
