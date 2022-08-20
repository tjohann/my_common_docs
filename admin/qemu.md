links and content around qemu and co
====================================

convert an virtualbox image to qemu image:

	qemu-img convert -f vdi -O qcow2 virtualbox_image.vdi qemu_image.qcow2

resize image:

	qemu-img resize my_image.qcow2 +50G


some common links
=================

https://www.poftut.com/qemu-tutorial/
https://wiki.ubuntuusers.de/QEMU/
https://wiki.archlinux.org/index.php/QEMU

http://cromwell-intl.com/linux/virtualization.html

create snapshots via virtsh:
----------------------------

https://linuxconfig.org/how-to-create-snapshots-of-qemu-kvm-guests#more-15608


linux realted
=============

using qemu for kernel development
---------------------------------

https://www.collabora.com/news-and-blog/blog/2017/01/16/setting-up-qemu-kvm-for-kernel-development/


android in qemu
---------------

https://www.collabora.com/news-and-blog/blog/2016/09/02/building-android-for-qemu-a-step-by-step-guide/


openbsd realted
===============

http://qemu-buch.de/de/index.php?title=QEMU-KVM-Buch/_QEMU_unter_OpenBSD
http://cromwell-intl.com/linux/openbsd-qemu-windows-howto.html


