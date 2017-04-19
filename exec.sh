#!/bin/bash

echo deleting build/*
rm -rf build
echo deleting bin/*
rm -rf bin

mkdir build

cd build
cmake ..
make
cd test
ctest
