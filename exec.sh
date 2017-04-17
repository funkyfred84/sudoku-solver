#!/bin/bash

echo deleting build/*
rm -rf build

mkdir -p build/unix

cd build/unix
cmake -G "Unix Makefiles" ../..
make

./bin/sudoku_test
