#!/usr/bin/env bash

git grep -I --name-only -z -e ' ' | xargs -0 gsed -i 's/[ \t]\+\(\r\?\)$/\1/'
