Some stuff around distcc
========================

I dont want to repeat what others already said, so here is a link to the distcc repo as a starting point -> https://github.com/distcc/distcc .
Note: for more detailed infos check https://wiki.gentoo.org/wiki/Distcc

So why do i want to use distcc? Actually for my A20_SDK (https://github.com/tjohann/a20_sdk.git) i do a cross compilation for the kernel and u-boot parts. Even thought the Allwinner A20 based devices like bananapi (https://en.wikipedia.org/wiki/Banana_Pi) are usable as a small desktop, it lacks computing performance to build huge code bases.

My A20 based cluster (baalue -> https://github.com/tjohann/a20_sdk/blob/master/pics/baalue_cluster_01.jpg) would be a good platform to play around with distcc. In the end i want to build void-packages (https://github.com/voidlinux/void-packages) native on the cluster, so no cross compilation anymore. Also all builds like u-boot or kernel should run on the cluster.

Another build starting point is to build the latest emacs version (http://ftp.gnu.org/gnu/emacs/emacs-25.2.tar.xz), because it's not available via void-packages.


Setup distcc
------------

The installation via xbps-install (distcc/distcc-pump/distcc-gtk) adds the two following config files:

	/etc/distcc/hosts
	/etc/distcc/clients.allow

The file hosts is a list of clients which distcc useses:

	127.0.0.1/2 192.168.0.1/4 192.168.0.80/2 192.168.0.81/2 192.168.0.82/2
	localhost my_power_machine baalue-01 baalue-02 baalue-03

Start with the most powerful node (192.168.0.1) and end with the least powerful node (192.168.0.82). Add the number of threads to use on the node (4 like 192.168.0.1/*4*). You can also add the lists of clients to ~/.distcc/hosts. Note that ./configure will run on the first machine listed, so it should be localhost. <- TODO: check if it performce better without localhost include (so localhost does only the preprocessing). Also check the impact of the number of threads (2-4 threads per node).

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


Summary setup
-------------

- add clients.allow to every node (with 192.168.0.0/24 to make it easier)
- add hosts to the server node with the list of all clients (127.0.0.1/2 192.168.0.80/2 192.168.0.81/2 192.168.0.82/2 ...)


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

Within a make based project you can use:

	make -j32 CC=distcc
	pump make -j32 CC=distcc

Show more infos:

	export DISTCC_VERBOSE=1

to build your project. Note: this will create a lot of output and costs a lot of extra time!

To save/show the temps set

	export DISTCC_SAVE_TEMPS=1

Do not use -march=native or -mtune=native in the CFLAGS or CXXFLAGS, because this could cause different optimisation on the different nodes (here on my build cluster it's not a problem).


Monitor the build process
-------------------------

To monitor the build process use distccmon-gnome or distccmon-text (distccmon-text 1 will update every second).

Distcc in action:

![Alt text](pics/libbaalue.png?raw=true "distcc in action")


Use distcc to build libbaalue
-----------------------------

Here're some build times of libbalue with and without using distcc.

without distcc:

	./configure CFLAGS='-g -O2' --prefix=/usr --sysconfdir=/etc --libdir=/usr/lib

	real 0m50,911s
	user 0m13,830s
	sys  0m24,740s

	real 0m53,792s
	user 0m14,150s
	sys  0m24,590s

with distcc (localhost not included and only one thread per node in distcc/hosts):

	./configure CFLAGS='-g -O2' --prefix=/usr --sysconfdir=/etc --libdir=/usr/lib CC=DISTCC

	real 0m55,736s
	user 0m14,450s
	sys  0m27,520s

Conclusion: use configure with distcc brings no perfomance gain


without distcc:

	make -j4

	real 0m33,942s
	user 0m33,760s
	sys  0m17,880s

with distcc (localhost not included and only one thread per node in distcc/hosts):

	make -j20 CC=distcc

	real 0m19,788s
	user 0m12,750s
	sys  0m16,950s

with distcc (localhost not included and 4 threads per node in distcc/hosts):

	make -j32 CC=distcc

	real 0m19,768s
	user 0m12,450s
	sys  0m17,260s

with distcc (localhost included and 4 threads per node in distcc/hosts):

     	make -j32 CC=distcc

	real 0m11,783s
	user 0m7,730s
	sys  0m7,710s


Measurement result:

- using distcc to build brings a performance gain
- to add the number of threads on the nodes makes no difference
- to add localhost brings another significant performance gain

Conclusion: "localhost baalue-01/4 baalue-02/4 baalue-03/4 baalue-04/4 baalue-05/4 baalue-06/4 baalue-07/4 baalue-08/4" and "make -j32 CC=distcc" brings the best perfomance.

TODO: check with pump and localhost removed from distcc/hosts


Use distcc to build baalued
---------------------------

Here're some build times of baalued with and without using distcc.

without distcc:

        make -j4

	real 0m4,577s
	user 0m2,200s
	sys  0m2,200s

with distcc (localhost included and 4 threads per node in distcc/hosts):

        make -j32 CC=distcc

	real 0m4,728s
	user 0m2,180s
	sys  0m2,310s

Measurement result:

- using distcc brings no performance gain


Use distcc to build linux kernel
--------------------------------

Example on how to build a linux kernel for a bananapi (https://github.com/tjohann/a20_sdk/blob/master/bananapi/Documentation/howto_kernel.txt)

without distcc:

	make -j4 LOADADDR=0x40008000 uImage modules dtbs

	real 439m48,806s
	user 701m3,820s
	sys  158m7,850s

with distcc (localhost NOT included in distcc/hosts and 4 threads per node):

	make CC=distcc -j32 LOADADDR=0x40008000 uImage modules dtbs

	real 176m21,388s
	user 210m21,680s
	sys  125m40,720s

with distcc (localhost included in distcc/hosts and 4 threads per node):

	make CC=distcc -j32 LOADADDR=0x40008000 uImage modules dtbs

	real    179m18,146s
	user    215m1,460s
	sys     126m22,640s


Example load off the build nodes 1:
![Alt text](pics/distcc_build_kernel_node_01.png?raw=true "load of node 01")

Example load off the build nodes 2:
![Alt text](pics/distcc_build_kernel_node_02.png?raw=true "load of node 02")

Example load off the build nodes 6:
![Alt text](pics/distcc_build_kernel_node_06.png?raw=true "load of node 06")

Example load off the build nodes 8:
![Alt text](pics/distcc_build_kernel_node_08.png?raw=true "load of node 08")

Measurement result:

- using distcc to build brings a performance gain
- to add localhost brings no significant performance gain

Conclusion: "localhost baalue-01/4 baalue-02/4 baalue-03/4 baalue-04/4 baalue-05/4 baalue-06/4 baalue-07/4 baalue-08/4" and "make -j32 CC=distcc" brings the best perfomance.

TODO: check with pump

Hint: CONFIG_GCOV_KERNEL must be turned off otherwise the build nodes wont be used. Also remember that the preprocessing and final linking steps are done on the local node (this can take 20-30% of the total time ... if not using pump) (see https://lwn.net/Articles/702375/)


Use distcc to build emacs
-------------------------

Howto build emacs (http://ftp.gnu.org/gnu/emacs/):

	./configure --with-x-toolkit=gtk2 --prefix=/usr/local


Use distcc with void-packages
-----------------------------

https://github.com/tjohann/a20_sdk/blob/master/bananapi/configs/conf_void_package_distcc



Use distcc to build arm926 toolchain/rootfs via buildroot for arietta
---------------------------------------------------------------------

Some background infos: https://wiki.gentoo.org/wiki/Distcc/Cross-Compiling

For my arietta devices/project i created a sdk repository (https://github.com/tjohann/arietta_sdk) similiar to the a20_sdk. It is the basic for a buildroot based root filesstem and cross-toolchain.


Masquerade mode
---------------

To generally use distcc instead of gcc or cc do the following (see also man distcc):

	mkdir /usr/lib/distcc/bin
    cd /usr/lib/distcc/bin
    ln -s ../../../bin/distcc gcc
    ln -s ../../../bin/distcc cc

Now add /usr/lib/distcc/bin to your $PATH *before* the "normal" gcc -> add it to the front. In void-linux the links are created by the distcc package.


Some more thoughts
------------------

There's a really interesting article form Willy Tarreau(http://1wt.eu/) about build farm/cluster and linux -> https://lwn.net/Articles/702375 (see the video https://www.youtube.com/watch?v=vwQ-KcjskRw&index=1&list=PLfnwKJbklIxwp09N5bM-Oj9bJzTAC3JsV and http://wiki.ant-computing.com/Choosing_a_processor_for_a_build_farm for his wiki)

Some summaries of that article:

	1). the project's build system must support parallel builds

This is one more reason to use autotools and co (see libbaalue/baalued/baalue)

	2). the project should be large, with many more source files than machines to build them on

So baalue(d) is not the right projects because there're only a few files to build, but libbaalue is better. Here i try to use abstraction based on the idea of functional modules for every bigger topic (like can or network). The measurment results above show prove summary 2.

	3). the compile time for each file should be approximately equal

Thats not easy to achieve, but i try to make every functional compounent/module not larger than 1000 lines of code. If its bigger, then i try to split the file in different modules.

	4). each machine needs to be running the exact same compiler

My build cluster constists out of 8 Bananapi and 1 Cubietruck with all the same rootfs (void-linux), so this is not a problem.
