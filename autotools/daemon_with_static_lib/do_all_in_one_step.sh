#!/bin/bash

make uninstall
make distclean

autoreconf --install || exit 1
./configure --prefix=$HOME

cd po
make update-po

cd ..
make
make install
