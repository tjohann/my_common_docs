#!/usr/bin/env bash

DISTFILE=/mnt/shared/distfiles

for f in *; do
    # && ! -L "$f" <- dont follow links
    if [[ -d "$f" && ! -L "$f" ]]; then
	echo "in $f -> it's a real directory, not a link";
	cp -f ${f}/* ${DISTFILE}
    fi;
done
