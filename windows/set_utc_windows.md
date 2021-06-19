Windows related topics
======================


Set UTC and make windows aware of it
------------------------------------

https://feldspaten.org/2019/11/03/windows-10-clock-in-utc/

The registry add (see RealTimeIsUniversal.reg file):

Windows Registry Editor Version 5.00

[HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\TimeZoneInformation]
  "RealTimeIsUniversal"=qword:00000001
