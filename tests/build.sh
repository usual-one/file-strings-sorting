#!/bin/bash
cmake -S . -B build
make -C build

./run.sh
