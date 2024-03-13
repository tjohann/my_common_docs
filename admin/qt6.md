QT6 Hints
=========


If QT6 is not in the PATH:

	qtchooser -install qt6 $(which qmake6)

which will create a file in your locat config

	/home/YOUR_ACCOUNT/.config/qtchooser/qt6.conf

Then add

	export QT_SELECT=qt6

to your .bashrc


If you want this systemwide available, copy the generated

	/home/YOUR_ACCOUNT/.config/qtchooser/qt6.conf

to

	/etc/xdg/qtchooser/

and change the link of default.conf:

	-rw-r--r--  1 root root   25 13. Mai 2023  4.conf
	-rw-r--r--  1 root root   26 13. Mai 2023  5.conf
	-rw-r--r--  1 root root   28 13. Mär 11:00 6.conf
	lrwxrwxrwx  1 root root    6 13. Mär 11:04 default.conf -> 6.conf


HINT: if qmake-qt6 is not in your lib dir, add it:

	lf /usr/bin/qmake*

	lrwxrwxrwx 1 root root  9 13. Mai 2023  /usr/bin/qmake -> qtchooser*
	lrwxrwxrwx 1 root root 22  9. Feb 12:46 /usr/bin/qmake-qt5 -> /usr/lib/qt5/bin/qmake*

This is possible missing:

	lrwxrwxrwx 1 root root 22 13. Mär 10:56 /usr/bin/qmake-qt6 -> /usr/lib/qt6/bin/qmake*
