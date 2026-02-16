# Chosfox Geonix R2

A customizable 47-key keyboard.

* Hardware supported: Chosfox Geonix R2 PCB with ES32FS026 microcontroller

Make example for this keyboard (after setting up your build environment):

    make chosfox/geonixr2:default

The keyboard supports VIA natively. Use the provided `VIA_Mapping_GeonixR2.JSON` file to configure it in VIA.

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

The ES32 ROM bootloader appears as a USB mass-storage device named
`RDMCTMZT DFU`.

To enter the bootloader:

1. Unplug the USB cable.
2. Switch the keyboard battery off.
3. Wait at least 15 seconds so the MCU loses power.
4. Hold the matrix position `(0,0)` key, normally Esc.
5. Connect the USB cable while you continue to hold the key.
6. Release the key after the mass-storage device appears.

The battery can keep the MCU powered after USB disconnect. Switching the
battery off is necessary when a running firmware image is unresponsive.

A working QMK image can also enter the bootloader through the `QK_BOOT`
keycode.

## Flashing

Build the firmware:

    make chosfox/geonixr2:default

Copy the resulting `.bin` file to the bootloader volume as `FLASH.BIN`.
The volume disconnects automatically, and the keyboard restarts with the new
firmware.

Flashing requires a USB connection. Bluetooth and 2.4GHz connections cannot
update the firmware.

## ChibiOS-Contrib dependency

This keyboard pins `lib/chibios-contrib` to commit
`16782528eda8d7471b768ce0f4b4458807b00328`.

That commit adds two required FS026 fixes:

- Correct the recursive include guard in `system_fs026.h`.
- Apply the USB address after the endpoint-zero status stage.

The USB change prevents intermittent descriptor timeouts during enumeration.
Do not replace this submodule commit until both fixes exist in the selected
ChibiOS-Contrib revision.
