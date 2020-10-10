#!/bin/bash
mkdir build
cd build
rm * -rf
cmake -DCMAKE_INSTALL_PREFIX=/usr ../gpio-indi-roof/
sudo make install

