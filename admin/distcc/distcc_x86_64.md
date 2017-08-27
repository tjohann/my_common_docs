Using distcc with two i7
========================

I have two i7 computer which i want to use to crossbuild kernels for my a20_sdk and to crossbuild arm926 root filesystems for my ariettas or imx233 boards. Both computer are not so different other the age:

The old one:

	i7-920
	6Gig DDR3 RAM@1033MHz
	500G HD@7200RPM (and 1000G@5400 for data sharing)

The new one:

	i7-7700K
	32Git DDR4 RAM@2400MHz
	256G SSD


Setup distcc
------------

[see distcc.md](README.md)


Check the config with hello-distcc build
----------------------------------------

To check if everthing works (see folder ./Programming), compile this small peace of code via distcc:

	#include <stdio.h>

	int main(void)
	{
		printf("Hello distcc\n");
		return 0;
	}


	export DISTCC_VERBOSE=1
	distcc gcc -c hello_distcc.c -o hello_distcc.o
	gcc main.o -o hello_distcc

Execute hello_distcc and then delete it to try with pump mode:

	pump distcc gcc -c hello_distcc.c -o hello_distcc.o
	gcc hello_distcc.o -o hello_distcc

Both versions should work.


General usage
-------------

[see distcc.md](README.md)

My used distcc/hosts entry:

	127.0.0.1/12 build-server/12

and with pump

	127.0.0.1,cpp,lzo/12 build-server,cpp,lzo/12

Summary of kdo's:

	/opt/a20_sdk/kernel/linux-4.12.9$ cp $ARMHF_HOME/bananapi/configs/kernel_config_4.12.x .config
	/opt/a20_sdk/kernel/linux-4.12.9$ make CROSS_COMPILE=arm-none-linux-gnueabihf- ARCH=arm menuconfig
	/opt/a20_sdk/kernel/linux-4.12.9$ make -j24 ARCH=arm CC="distcc /opt/a20_sdk/toolchain/bin/arm-none-linux-gnueabihf-gcc" CROSS_COMPILE="/opt/a20_sdk/toolchain/bin/arm-none-linux-gnueabihf-" LOADADDR=0x40008000 uImage modules
	/opt/a20_sdk/kernel/linux-4.12.9$ pump make -j24 ARCH=arm CC="distcc /opt/a20_sdk/toolchain/bin/arm-none-linux-gnueabihf-gcc" CROSS_COMPILE="/opt/a20_sdk/toolchain/bin/arm-none-linux-gnueabihf-" LOADADDR=0x40008000 uImage modules


Useful link:

	http://blog.samarthparikh.com/2012/10/install-distcc-and-make-linux-kernel.html


Monitor the build process
-------------------------

[see distcc.md](README.md)


Use distcc to build linux kernel
--------------------------------

Example on how to build a linux kernel for a bananapi (https://github.com/tjohann/a20_sdk/blob/master/bananapi/Documentation/howto_kernel.txt).

without distcc (i7-920):

	make -j10 ARCH=arm CROSS_COMPILE=arm-none-linux-gnueabihf- LOADADDR=0x40008000 uImage modules

	real 13m19,910s
	user 95m4,201s
	sys	 8m27,532s

without distcc (i7-7700K):

	make -j10 ARCH=arm CROSS_COMPILE=arm-none-linux-gnueabihf- LOADADDR=0x40008000 uImage modules

	real 5m35,205s
	user 39m58,705s
	sys	 3m3,940s


with distcc (localhost included in distcc/hosts and 12 threads per node):

	make -j24 ARCH=arm CC="distcc /opt/a20_sdk/toolchain/bin/arm-none-linux-gnueabihf-gcc" CROSS_COMPILE="/opt/a20_sdk/toolchain/bin/arm-none-linux-gnueabihf-" LOADADDR=0x40008000 uImage modules

	real 4m56,033s
	user 16m36,729s
	sys	 1m54,906s

![Alt text](pics/distcc_crossbuild_kernel.png?raw=true "distcc in action (normal mode)")

with pump (localhost included in distcc/hosts and 12 threads per node):

	pump make -j24 ARCH=arm CC="distcc /opt/a20_sdk/toolchain/bin/arm-none-linux-gnueabihf-gcc" CROSS_COMPILE="/opt/a20_sdk/toolchain/bin/arm-none-linux-gnueabihf-" LOADADDR=0x40008000 uImage modules

	real 6m11,211s
	user 13m16,762s
	sys	 1m39,230s

![Alt text](pics/distcc_pump_crossbuild_kernel.png?raw=true "distcc in action (pump mode)")


Use distcc with void-packages
-----------------------------

t.b.d.


Use distcc to build arm926 toolchain/rootfs via buildroot for arietta
---------------------------------------------------------------------

Some background infos: https://wiki.gentoo.org/wiki/Distcc/Cross-Compiling

t.b.d.


Masquerade mode
---------------

[see distcc.md](README.md)
