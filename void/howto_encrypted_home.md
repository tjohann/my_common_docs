Howto to encrypt your home directory
====================================

Setup yout home dir after installation for an ecryption


Before start
------------

Create a tgz of your home directory so that you can unpack it in the new encrypted partition.

Add to /etc/dracut.conf

	install_items+="/etc/crypttab"



Create encrypted partition
-------------------------


Bsp:

	cryptsetup luksFormat /dev/nvme0n1p4
	cryptsetup luksOpen /dev/nvme0n1p4 c_home
	mkfs.ext4 /dev/mapper/c_home


Add partition to /etc/cryptab

	c_home     UUID=12345678-abcd-1234-5678-1234567890ab    none    luks,timeout=30

Add partition to /etc/fstab

	/dev/mapper/c_home         /home/username    ext4   defaults    0    2


Make it work:

	xbps-reconfigure -fa
