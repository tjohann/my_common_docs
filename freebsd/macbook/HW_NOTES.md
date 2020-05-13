some HW related notes to my mycbook
===================================

https://www.heise.de/mac-and-i/produkte/macbook-pro-15-2-4-ghz-mitte-2007-96/


loader.conf adds
----------------

nvidia_load="YES"


xorg.conf.d adds
----------------

20-video.conf

Section "Device"
    Identifier "NVIDIA Card"
    VendorName "NVIDIA Corporation"
    Driver "nvidia"
EndSection
