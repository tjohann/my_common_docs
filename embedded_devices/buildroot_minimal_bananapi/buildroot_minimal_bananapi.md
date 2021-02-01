Setup of an minimal buildroot image for a bananapi
==================================================

Goals: setup a minimal image with non "mainstream" components
Additions: see https://git.buildroot.net/buildroot/tree/board/bananapi/bananapi-m1

In folder buildroot_minimal_bananapi you can find the .config`s for the different steps and on sourceforge.net (https://sourceforge.net/projects/a20-minimum-buildroot/) you can find the packed image folder.


Starting point (bananapi_minimal_config_buildroot_v01)
------------------------------------------------------

Build the default image and do some first changes (to make it build again)

	make bananapi_m1_defconfig
	make menuconfig

Changes to build:

	change uboot version to 2020.10 (due to error -> double definition of yylloc)
	change kernel to 4.19.172 (same error like in u-boot)
	change kernel header of uClibc-ng to 4.19

Additional change: i have a common folder where i download all tarballs and such stuff

	change download dir to /mnt/shared/tarballs

Build all:

	make

Write image to sdcard:

	sudo dd if=output/images/sdcard.img of=/dev/sde (change sde to your device!)
	sync

Connect via serial (115200 8N1) to the device
Summary in result_bananapi_minimal_config_buildroot_v01.txt
Images in bananapi_minimal_image_v01.tgz


Change to musl (bananapi_minimal_config_buildroot_v02)
------------------------------------------------------

Change from uClibc-ng to musl and build again.

Summary in result_bananapi_minimal_config_buildroot_v02.txt
Images in bananapi_minimal_image_v02.tgz

Results:

	/dev/root increase from 2,7 to 2,8M
	startup time more or less the same

NOTE: i moved everthing in a new repository@github -> see https://github.com/tjohann/a20_minimum_buildroot_dev


Adapt init system from busybox (bananapi_minimal_config_buildroot_v03)
----------------------------------------------------------------------

Copy my_busybox.config to package/busybox/my_busybox.config and use bananapi_minimal_config_buildroot_v03 .

Summary in result_bananapi_minimal_config_buildroot_v03.txt
Images in bananapi_minimal_image_v03.tgz

Results:

	busybox do not realy provide runit -> so change init system to OpenRC


Change init system to OpenRC (bananapi_minimal_config_buildroot_v04)
--------------------------------------------------------------------

Change init system to OpenRC and build again.

Note: OpenRC is already part of buildroot, so no new parts are needed

Summary in result_bananapi_minimal_config_buildroot_v04.txt
Images in bananapi_minimal_image_v04.tgz

Results (compare with v02 -> v03 makes no sense):

	/dev/root increase from 2,7 to 4,6M (as expected)
	memory consumption is increasing (as expected)
	startup time decreases (as expected)
