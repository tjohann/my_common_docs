Possible xbps-install errors
============================


Update after some time
----------------------

Last login: Thu Jan  1 01:00:30 on tty1
Setup env for host "armv7l" with root dir "/var/lib/a20_sdk" and bin root dir "/opt/a20_sdk"
root@bananapi:~# SSL_NO_VERIFY_PEER=1 xbps-install -Su
[*] Updating repository `https://alpha.de.repo.voidlinux.org/current/armv7l-repodata' ...
SSL certificate subject doesn't match host alpha.de.repo.voidlinux.org
ERROR: [reposync] failed to fetch file `https://alpha.de.repo.voidlinux.org/current/armv7l-repodata': Operation not permitted
[*] Updating repository `https://alpha.de.repo.voidlinux.org/current/nonfree/armv7l-repodata' ...
SSL certificate subject doesn't match host alpha.de.repo.voidlinux.org
ERROR: [reposync] failed to fetch file `https://alpha.de.repo.voidlinux.org/current/nonfree/armv7l-repodata': Operation not permitted
[*] Updating repository `https://alpha.de.repo.voidlinux.org/current/debug/armv7l-repodata' ...
SSL certificate subject doesn't match host alpha.de.repo.voidlinux.org
ERROR: [reposync] failed to fetch file `https://alpha.de.repo.voidlinux.org/current/debug/armv7l-repodata': Operation not permitted

Possible fixes:

	SSL_NO_VERIFY_PEER=1 xbps-install -Su

	xbps-pkgdb -a
	xbps-reconfigure -f ca-certificates

Another possible problem is, that the server is down. Then change to:

	xxxx@xxxxx:/usr/share/xbps.d$ lf
	-rw-r--r--   1 root root   54 18. Sep 15:29 00-repository-main.conf
	-rw-r--r--   1 root root   71 28. Mai 2022  10-repository-multilib-nonfree.conf
	-rw-r--r--   1 root root   63 28. Mai 2022  10-repository-multilib.conf
	-rw-r--r--   1 root root   62 28. Mai 2022  10-repository-nonfree.conf
	-rw-r--r--   1 root root   60 28. Mai 2022  20-repository-debug.conf
	xxxx@xxxxx:/usr/share/xbps.d$ cat 00-repository-main.conf
	repository=https://repo-default.voidlinux.org/current
	xxxx@xxxxx:/usr/share/xbps.d$ cat 10-repository-
	cat: 10-repository-: Datei oder Verzeichnis nicht gefunden
	xxxx@xxxxx:/usr/share/xbps.d$ cat 10-repository-nonfree.conf
	repository=https://repo-default.voidlinux.org/current/nonfree
	xxxx@xxxxx:/usr/share/xbps.d$ cat 20-repository-debug.conf
	repository=https://repo-default.voidlinux.org/current/debug

Also see:

	https://docs.voidlinux.org/xbps/troubleshooting/common-issues.html
