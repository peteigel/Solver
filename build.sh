#!/usr/bin/env bash

set -e

mkdir -p build lib bin
cd build
cmake ..
make
../bin/tests
