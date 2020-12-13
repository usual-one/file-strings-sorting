#!/bin/bash
cmake -S . -B build
make -C build

if [[ $1 != "" ]]
then
  ./run.sh $1
fi
