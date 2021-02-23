Some notes around raspi4
========================

for PINout see https://de.pinout.xyz/#


GPIO
----

usermod -a -G gpio <username>

https://elinux.org/RPi_Tutorial_EGHS:LED_output
https://elinux.org/RPi_Tutorial_EGHS:Switch_Input

GPIO22 (physical pin 14) -> ground
GPIO23 (physical pin 16) -> LED
GPIO24 (physical pin 18) -> switch

use libgpiod -> https://kernel.googlesource.com/pub/scm/libs/libgpiod/libgpiod/+/v0.2.x/README.md

hints:

	max 50mA per PIN

