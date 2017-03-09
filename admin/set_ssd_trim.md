some hints about ssd handling
=============================

https://sites.google.com/site/easylinuxtipsproject/ssd

z.B.
----

cat /sys/block/sda/queue/scheduler
-> noop deadline [cfq] 

to change it to deadline
GRUB_CMDLINE_LINUX_DEFAULT="elevator=deadline quiet splash"
