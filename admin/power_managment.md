stuff around linux power managment
==================================


change cpu freq governor
-----------------------

for c in $(ls -d /sys/devices/system/cpu/cpu[0-9]*); do echo ondemand >$c/cpufreq/scaling_governor; done



high power consumption in sleep mode
------------------------------------

https://www.heise.de/ct/hotline/Linux-Hoher-Stromverbrauch-im-Standby-3717127.html

deactivate wake on lan: sudo ethtool -s eth0 wol d
