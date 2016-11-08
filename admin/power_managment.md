stuff around linux power managment
==================================


change cpu freq governor
-----------------------

for c in $(ls -d /sys/devices/system/cpu/cpu[0-9]*); do echo ondemand >$c/cpufreq/scaling_governor; done
