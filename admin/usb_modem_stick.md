some links about usb modem stick
================================

https://trick77.com/setting-up-huawei-e3276-150-4g-lte-usb-modem-ubuntu-server-desktop/

http://www.gnuton.org/blog/2015/07/huawei-e3372/

http://unix.stackexchange.com/questions/213663/huawei-e3372s-linux-rasbian-incoming-connections-problem


Some useful cmd
----------------

	dhclient -v eth1
	ip route show | grep default

	ip route del default ; ip route add default via 192.168.1.1

	ping 8.8.8.8  (possible dns server)



Howto setup ethX the "hard" way
-------------------------------

	ip link set dev eth0 up
	ip addr add 192.168.0.103/255.255.255.0 broadcast 192.168.0.255 dev eth0
	ip route add default via 192.168.0.1


Change mode of stick (router to modem)
--------------------------------------

http://www.lteforum.at/mobilfunk/huawei-e3372-flashen-so-gehts-non-hilink.1683/

http://blog.asiantuntijakaveri.fi/2015/07/convert-huawei-e3372h-153-from.html
