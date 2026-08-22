Hackyy Pad

A custom 4-key macropad with a rotary encoder and OLED display, designed and built from scratch for the Hack Club Stardance challenge.
What it is

I built this macropad as a dedicated physical controller for deep-work sessions and creative workflow. Instead of memorizing awkward multi-key shortcuts or reaching for a mouse, my most frequent actions are mapped directly to physical switches, a clickable knob, and an active OLED screen.
Layout & Controls

    Rotary Encoder (Knob):
        Turn: Master volume control
        Click: Play / Pause media
    Switch 1: Instant audio mute (lifesaver when jumping into unexpected calls)
    Switch 2: Skip to next track
    Switch 3: Switch virtual desktops instantly (my dedicated "hide distractions / focus" button)
    Switch 4: Custom macro that instantly types out the Gumroad link for my new project
    0.91" OLED Screen: Renders an animated Bongo Cat that furiously taps its paws whenever I turn the knob or hit any of the switches.

Hardware & 3D Enclosure Design
PCB & Schematic (KiCad)

I designed the custom PCB from the ground up in KiCad, centered around the Seeed Studio XIAO RP2040. Because this is a compact 4-key build, I didn't need to overcomplicate things with a standard diode matrix. Instead, I learned how to wire each switch directly between a microcontroller GPIO pin and ground—keeping the circuit clean and straightforward.
Case Modeling (Onshape)

Designing physical enclosures was completely new territory for me. I modeled a custom two-part 3D-printable shell in Onshape (Hackyy - Part 1 and Part 2). The hardest part was dialing in the exact tolerances so the OLED display, mechanical switch plate, and rotary encoder seated flush without rattling or pinching wires.
Firmware & Pairing with AI

Rather than just copying and pasting blocks of code, I treated AI like a patient tutor and senior pair-programmer across the entire build:

    Hardware & CAD: It helped break down 3D modeling concepts in Onshape and guided me through the logic of translating my physical KiCad schematic pinouts into the right QMK GPIO matrix in keyboard.json.
    C Syntax & Debugging: It helped me decode massive walls of cryptic red GCC compiler errors. I learned the hard way how unforgiving strict C can be—like when a single rogue lowercase l inside an enum completely crashed an entire build.
    OLED Animation: It helped me write the frame-swapping logic required to render the Bongo Cat bitmaps without blocking the main key-scanning loop.

The 1.5-Hour Tragedy 😭

The most painful part of this entire challenge wasn't the C compiler, the KiCad routing, or 3D modeling tolerances—it was the time tracker.

I spent over an hour and a half deep in the zone writing and flashing code, only to discover my Hackatime session had been logging to the completely wrong project on my Stardance dashboard. Over 1.5 hours of tracked work vanished into the void.

Lesson learned: Always double-check your project dropdown before starting a sprint!