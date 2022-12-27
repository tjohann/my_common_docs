Howto setup a home git server (simple)
======================================


links
-----

https://brzegtalerza.pl/git.html

https://git-scm.com/book/en/v2/Git-on-the-Server-Setting-Up-the-Server
https://git-scm.com/book/en/v2/Git-on-the-Server-Generating-Your-SSH-Public-Key

https://chemicloud.com/kb/article/ssh-authentication-refused-bad-ownership-or-modes-for-directory/


commands clients
----------------

Generate a key and copy the pub file to the server:

	ssh-keygen -o -f id_rsa_my_git_key

Copy the pub part of the key to the server.

Add your keys to the ssh config (~/.ssh/config):

	Host raspi4
		HostName raspi4
		IdentityFile ~/.ssh/id_rsa_my_git_key
		User git


commands servers
----------------

Add user git:

	sudo useradd -m -c "git repo" -s /usr/bin/git-shell git

Create .ssh folder

	sudo -u git "mkdir" "/home/git/.ssh"

Copy all pub keys to .ssh folder.

Create authorized\_keys file and add the first key (id\_rsa\_my\_git\_key.pub)

	sudo -u git "sh" "-c" 'echo no-port-forwarding,no-X11-forwarding,no-agent-forwarding,no-pty YOUR_PUBLIC_KEY >> /home/git/.ssh/authorized_keys'

here:

	sudo -u git "sh" "-c" 'echo no-port-forwarding,no-X11-forwarding,no-agent-forwarding,no-pty id_rsa_my_git_key.pub >> /home/git/.ssh/authorized_keys'

Do this for all pub keys.

An alternativ way ist to cat all the pub keys into the authorized\_keys file:

	cat ./id\_rsa\_my\_git\_key.pub >> ~/.ssh/authorized_keys

**Important**: Check for the acces rights of the different folders and files and correct them if needed:

	chmod 700 /home/git
	chmod 700 /home/git/.ssh
	chmod 600 /home/git/.ssh/authorized_keys


create empty repo (server)
--------------------------

	sudo -u git "mkdir" "-p" "/home/git/repos/YOUR_REPO_NAME.git"
	sudo -u git "git" "init" "--bare" "/home/git/repos/YOUR_REPO_NAME.git"


clone repo
----------

	git clone git@raspi4:/home/git/repos/YOUR_REPO_NAME.git
