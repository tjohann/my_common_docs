# relevant links


xorg/desktop/laptop stuff
-------------------------
https://cooltrainer.org/a-freebsd-desktop-howto/

https://vermaden.wordpress.com/freebsd-desktop/
https://vermaden.wordpress.com/2018/11/20/freebsd-desktop-part-2-1-install-freebsd-12/

https://i-bsd.com/drm-console/
https://www.c0ffee.net/blog/freebsd-on-a-laptop/
https://github.com/FreeBSDDesktop
https://www.freebsd.org/cgi/man.cgi?query=xkeyboard-config&sektion=7&manpath=freebsd-release-ports

https://danschmid.de/freebsd/xorg-und-videotreiber/
https://dataswamp.org/~solene/2020-05-11-freebsd-workstation.html?utm_source=discoverbsd
https://www.daemonology.net/blog/2020-05-22-my-new-FreeBSD-laptop-Dell-7390.html?utm_source=discoverbsd


handling touchpad and typing
----------------------------
https://blog.grem.de/pages/t470s.html


specific graphics stuff
-----------------------
https://wiki.freebsd.org/Graphics
https://www.freebsd.org/doc/en_US.ISO8859-1/books/handbook/x-config.html


clamav stuff
------------
https://blog.socruel.nu/freebsd/how-to-install-and-configure-clamav-on-freebsd.html?utm_source=discoverbsd


distcc stuff
------------
https://kukunotes.wordpress.com/2011/09/05/freebsd-installing-ports-via-distcc/


grub stuff
----------
https://www.nixcraft.com/t/any-remote-boot-select-for-the-grub-menu-over-tcp-ip/1003


old images
----------
http://ftp-archive.freebsd.org/pub/FreeBSD-Archive/old-releases/amd64/


get and update base system
--------------------------

svnlite checkout https://svn.freebsd.org/base/stable/12 /usr/src/
set SVN_UPDATE="YES" in /etc/src.conf
and after first checkout use make udate


file system with fuse ... like xfs
----------------------------------

https://forums.freebsd.org/threads/xfs-support.61449/

pkg install fusefs-lkl
fuse_load="YES" in loader.conf
gpart show -p /dev/da0 ... to see the partitions within da0
lklfuse -o type=xfs /dev/da0s1 /mnt
