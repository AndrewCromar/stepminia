# Firmware

The firmware is the program that runs on the RP2040. Once it's installed, the
pad shows up to your computer as a plain USB keyboard, no drivers or extra
software needed. Each button or contact pad simply types a key.

## What it does

When you press a button (or bridge a contact pad), the pad sends a key press:

| Input | Key sent |
| --- | --- |
| Up | Arrow Up |
| Down | Arrow Down |
| Left | Arrow Left |
| Right | Arrow Right |
| Plus (+) | Enter |
| Minus (−) | Escape |

These are the keys Stepmania (and most rhythm games) use by default, so the pad
works out of the box.

## Get the firmware

The easy option is the **pre-compiled file**, a single `.uf2` you drag onto the
board, no tools required.

- [Download the pre-compiled `.uf2`](https://github.com/AndrewCromar/stepminia/raw/main/firmware/stepminia.uf2) — recommended.
- [Firmware source code](https://github.com/AndrewCromar/stepminia/tree/main/firmware) (`repo/firmware/`) — if you want to read or change it.

## Install it

1. **Unplug** the pad from your computer.
2. Hold down the `BOOTSEL` button on the RP2040, and *while holding it*, plug the
   pad back into your computer.
3. The pad mounts as a USB drive. You can
   let go of the button now.
4. **Drag the `.uf2` file onto that drive.**

The pad reboots automatically and the drive disappears, that's normal, it means
the firmware installed. It's now running as a keyboard.

## Test it

Press any button, or bridge two contact pads together (a strip of aluminum foil
works well), and check that the matching key registers. The
[keyboard tester](https://keyboard-tester.com/) site is a quick way to see your
presses live in the browser.

## Build it yourself (optional)

The source is a [PlatformIO](https://platformio.org/) project for the Waveshare
RP2040-Zero. With PlatformIO installed, open the `firmware/` folder and run:

```bash
pio run            # compile
pio run -t upload  # compile and flash a connected board
```

Compiling also produces a fresh `stepminia.uf2` you can install by hand using the
steps above.
