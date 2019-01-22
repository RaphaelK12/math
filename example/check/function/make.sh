#!/bin/bash

pwd

g++ -fexceptions -std=c++11 -g -I../../../src clamper_test.cpp             -o  clamper_test
g++ -fexceptions -std=c++11 -g -I../../../src peano_test.cpp               -o  peano_test
g++ -fexceptions -std=c++11 -g -I../../../src distribution.cpp             -o  distribution
g++ -fexceptions -std=c++11 -g -I../../../src vap.cpp                      -o  vap
g++ -fexceptions -std=c++11 -g -I../../../src gabor.cpp                    -o  gabor

