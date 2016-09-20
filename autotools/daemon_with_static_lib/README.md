baalued - bananapi cluster node controller
==========================================

The baalue daemon provide an TCP/UDP interface to a bananapi cluster node. With that interface you can control and trigger standard task on such cluster node. Although its named bananapi cluster node daemon you can use it on any other target devices too.

Baalued is part of my sdk's like https://github.com/tjohann/a20_sdk.git and the related sdk tool (https://github.com/tjohann/sdk_builder.git). It runs on a embedded device like Bananapi-M1. To interact/control the daemon you can use my XFCE-toolbar (tbd.) tool, my sdk_builder or baalue (https://github.com/tjohann/baalue.git).


Requirements
------------

To build and run baalued you need libbaalue (https://github.com/tjohann/libbaalue.git), no other libs/tools needed.


Functions
---------

Baalued provides some basic functionallities like

	1). shutdown the device
	2). check for config updates (sdk_builder.git and a20_sdk.git)
	3). ...


Configuration/defaults
----------------------

	Port TCP/UDP - 20202 (Common control of a target device)
	Port TCP/UPD - 20203 (Bananapi cluster node specific services)


Shutdown a device
-----------------

For a safe shutdown you should never direct unplug the (embedded) device from power. So this function provides the a simple access to remotly shutdown your (embedded) device.