some common info about allwinner boards
=======================================


mainline support for allwinner prozs
------------------------------------

http://linux-sunxi.org/Linux_mainlining_effort


can support for allwinner driver
--------------------------------

https://git.kernel.org/cgit/linux/kernel/git/torvalds/linux.git/commit/?id=0738eff14d817a02ab082c392c96a1613006f158



audio support for bananapi and co
---------------------------------

xbps-install -Su alsa-plugins alsa-tools alsa-tools-devel alsa-utils

for analog output:

root@baalue_master:/etc# cat asound.conf
pcm.!default {
        type hw
        card 0
        device 0
}

ctl.!default {
        type hw
	card 0
}


for hdmi output:
root@baalue_master:/etc# cat asound.conf
pcm.!default {
        type hw
	card 1
	device 0
}

ctl.!default {
        type hw
        card 1
}
