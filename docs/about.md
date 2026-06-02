# About

Stepminia is a desktop finger Stepmania dance-pad — a little open-hardware DDR pad you
tap with your fingers. Everything to build one lives in the
[GitHub repo](https://github.com/AndrewCromar/stepminia).

## PCB

Made in KiCad. The production files are in the `pcb` folder, ready to be manufactured
(e.g. JLCPCB).

You may notice the simple, integrated PCBs. This is because I wanted to learn how to
integrate a microcontroller (RP2040) directly into my PCB design — but when I went to
have it made it was going to cost around $100. That's not a huge amount, but I have other
things I want to buy right now, so I made the simple version that just has holes for a
Waveshare Zero to be soldered on.

## Firmware

The firmware is in the `firmware` folder, and there will likely be a compiled version in
that folder too. See the [Firmware](guide/firmware.md) page in the guide for details.

## CAD

Right now the CAD is being made in OnShape, so there aren't local files yet. The STLs
will go in the `cad` folder once they're done — and ideally a link to the OnShape files
and/or SolidWorks parts so people can make changes.
