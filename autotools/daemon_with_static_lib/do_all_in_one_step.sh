#!/bin/bash

export PKG_CONFIG_PATH=/usr/local/lib/pkgconfig:${PKG_CONFIG_PATH}

make uninstall
make distclean

autoreconf --install || exit 1
./configure --prefix=$HOME --enable-debug

cd po
make update-po

cd ..
make
make install
