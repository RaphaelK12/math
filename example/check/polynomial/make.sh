#!/bin/bash

pwd

cd ./solve
./make.sh
cd ..

g++ -fexceptions -std=c++11 -g -I../../../src evaluate.cpp               -o  evaluate

