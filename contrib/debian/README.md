
Debian
====================
This directory contains files used to package argentumd/argentum-qt
for Debian-based Linux systems. If you compile argentumd/argentum-qt yourself, there are some useful files here.

## argentum: URI support ##


argentum-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install argentum-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your argentum-qt binary to `/usr/bin`
and the `../../share/pixmaps/argentum128.png` to `/usr/share/pixmaps`

argentum-qt.protocol (KDE)

