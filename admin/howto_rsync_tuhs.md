#
# http://www.tuhs.org/
#

mkdir Applications 4BSD PDP-11 PDP-11/Trees VAX Other

rsync -avz minnie.tuhs.org::UA_Root .
rsync -avz minnie.tuhs.org::UA_Applications Applications
rsync -avz minnie.tuhs.org::UA_4BSD 4BSD
rsync -avz minnie.tuhs.org::UA_PDP11 PDP-11
rsync -avz minnie.tuhs.org::UA_PDP11_Trees PDP-11
rsync -avz minnie.tuhs.org::UA_VAX VAX
rsync -avz minnie.tuhs.org::UA_Other Other


Git-Repo
--------

https://lwn.net/Articles/725297/
https://github.com/dspinellis/unix-history-repo
