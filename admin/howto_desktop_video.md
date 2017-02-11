Simple howto around desktop videos
----------------------------------

https://www.youtube.com/watch?v=nbKrGq_KTis
https://wiki.ubuntuusers.de/Screencasts/#recordMyDesktop

https://linuxundich.de/gnu-linux/desktop-inklusive-ton-mit-gtk-recordmydesktop-aufnehmen/


using vlc
---------

vlc screen:// --screen-fps 25 --nooverlay --sout "#transcode{vcodec=h264,vb=2048,scale=1.0,acodec=mp3,ab=128,channels=2}:duplicate{dst=std{access=file,mux=mp4,dst=screencast.flv}}"
