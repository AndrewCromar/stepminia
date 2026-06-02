# PCB

The PCB is the heart of the pad. It carries the RP2040 microcontroller, contact pads, and buttons. There are two versions to choose from.

## Which version should I choose?

| Version | RP2040 | Best for |
| --- | --- | --- |
| **Simple** | A separate [Waveshare RP2040-Zero](https://www.waveshare.com/wiki/RP2040-Zero) board solders onto pads on the PCB. | Beginners, or anyone who'd rather solder one pre-made module than place lots of small parts. Cheaper to start, easier to assemble by hand. |
| **Integrated** | The RP2040 chip is mounted directly on the board, no second board needed. | A cleaner, single-board build. Requires placing many very small parts, so it's better suited to a PCB-assembly service or experienced solderers. |

Pick whichever matches your skill level and budget, both produce the same finished Stepminia pad.

## Getting the files

For each version you have two options:

- **Order it as-is**, download the ready-made JLCPCB production `.zip` and
  upload it straight to [JLCPCB](https://jlcpcb.com/) (or a similar fab house).
  This is the fast path.
- **Open or edit the design**, grab the [KiCad](https://www.kicad.org/) source
  if you want to inspect, modify, or regenerate the board yourself.

!!! note
    Using the ready-made production files is recommended.


### Simple

- [Download JLCPCB production files (.zip)](https://github.com/AndrewCromar/stepminia/raw/main/pcb/simple/production.zip).
- [KiCad source files](https://github.com/AndrewCromar/stepminia/tree/main/pcb/simple) (`repo/pcb/simple/`).

### Integrated

- [Download JLCPCB production files (.zip)](https://github.com/AndrewCromar/stepminia/raw/main/pcb/integrated/production.zip).
- [KiCad source files](https://github.com/AndrewCromar/stepminia/tree/main/pcb/integrated) (`repo/pcb/integrated/`).