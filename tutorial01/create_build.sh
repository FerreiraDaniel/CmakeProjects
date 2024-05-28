#!/bin/sh

mkdir -p build
cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE_TYPE=Debug -B build
cd build
ls
cd ..