#!/bin/sh

# This is the IP of 'tap' on the Slackware/x86 host:
BRIDGEIP=192.168.0.55

modprobe tun
/sbin/ifconfig $1 $BRIDGEIP netmask 255.255.255.0
/sbin/brctl addif br0 $1
