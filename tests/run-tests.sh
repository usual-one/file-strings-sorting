#!/bin/bash
echo "Running unit tests..."
./run-unit-tests.sh
echo "Running white-box tests..."
./run-black-box-tests.sh
