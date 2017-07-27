some stuff for my blog around distcc
====================================

I dont want to repeat what others already said, so here is a link to the distcc repo as a starting point -> https://github.com/distcc/distcc . For more detailed infos check https://wiki.gentoo.org/wiki/Distcc and 

So why do i want to use distcc? Actually for my A20_SDK (https://github.com/tjohann/a20_sdk.git) i do a cross compilation for the kernel and u-boot parts. Even thought the Allwinner A20 based devices like bananapi (https://en.wikipedia.org/wiki/Banana_Pi) are usable as a small desktop, it lacks computing performance to build such huge code bases. 

My A20 based cluster (baalue -> https://github.com/tjohann/a20_sdk/blob/master/pics/baalue_cluster_01.jpg) would be a good platform to play around with distcc. In the end i want to build void-packages (https://github.com/voidlinux/void-packages) native on the cluster, so no cross compilation anymore. 

The build starting point is to build the latest emacs version (http://ftp.gnu.org/gnu/emacs/emacs-25.2.tar.xz).


setup distcc
------------

The installation via xbps-install (distcc/distcc-pump/distcc-gtk) adds the two following config files:

	/etc/distcc/hosts
	/etc/distcc/clients.allow

The file hosts is a list of clients which distcc useses:

	127.0.0.1/2 192.168.0.1/4 192.168.0.80/2 192.168.0.81/2 192.168.0.82/2
	localhost my_power_machine baalue-01 baalue-02 baalue-03
	
Start with the most powerful node (192.168.0.1) and end with the least powerful node (192.168.0.82). Add the number of threads to use on the node (4 like 192.168.0.1/*4*). You can also add the lists of clients to ~/.distcc/hosts. Note that /configure will run on the first machine listed, so it should be localhost. <- TODO: check if it performce better without localhost include (so localhost does only the preprocessing). Also check the impact of the number of threads (2-4 threads per node).

The clients.allow (https://github.com/tjohann/a20_sdk/blob/master/bananapi/configs/clients.allow_distcc) is a list of networks or nodes which are allowed to use this node.

	192.168.0.0/24 192.168.0.1
	
Per default distcc log to /var/log/messages.log. To change the log level and the log location add --log-level notice --log-file /var/log/distccd.log to /etc/sv/distcc/run (i added it to the OPTIONS field).

Distcc respects the $TMPDIR environment variable when creating its scratch directory. <- TODO: check this

To set the number used threads add 

	MAKEOPTS='-j20'
	MAKEFLAGS='-j20'

to /etc/make.conf or 

	export MAKEOPTS='-j20'
	export MAKEFLAGS='-j20'
	
to ~/.bashrc.

To use zeroconf via avahi add "+zeroconf" to hosts (i dont use it).


summary setup
-------------

- add clients.allow to every node (with 192.168.0.0/24 to make it easier)
- add hosts to the server node with the list of all clients (127.0.0.1/2 192.168.0.80/2 192.168.0.81/2 192.168.0.82/2 ...)


check the config with hello-distcc build
----------------------------------------

To check if everthing works, compile this small peace of code via distcc:

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
	gcc main.o -o hello_distcc 

Both versions should work.


general usage
-------------

Within a make based project you can use:

	make -j20 CC=distcc 
	pump make -j20 CC=distcc

Show more infos:

	export DISTCC_VERBOSE=1
	
to build your project.	

To save/show the temps set

	export DISTCC_SAVE_TEMPS=1

Do not use -march=native or -mtune=native in the CFLAGS or CXXFLAGS, because this coudl cause different optimisation on the different nodes (here on my build cluster it's not a problem). <- TODO: check that


monitor the build process
-------------------------

To monitor the build process use distccmon-gnome or distccmon-text (distccmon-text 1 will update every second). <- TODO: check if distccmon-text is available


use distcc to build libbaalue/baalued and baalue
------------------------------------------------

t.b.d.
	

use distcc to build emacs
-------------------------

t.b.d.


use distcc with void-packages
-----------------------------

https://github.com/tjohann/a20_sdk/blob/master/bananapi/configs/conf_void_package_distcc
	


use distcc to build arm926 toolchain/rootfs via crosstool for arietta
---------------------------------------------------------------------

Some background infos: https://wiki.gentoo.org/wiki/Distcc/Cross-Compiling 

For my arietta devices/project i created a sdk repository (https://github.com/tjohann/arietta_sdk) similiar to the a20_sdk. It is the basic for a buildroot based root filesstem and cross-toolchain.


