#!/bin/bash

echo deleting build/*
rm -rf build
echo deleting bin/*
rm -rf bin

mkdir build

cd build
LANG=C cmake ..
LANG=C make
cd test
LANG=C ctest
