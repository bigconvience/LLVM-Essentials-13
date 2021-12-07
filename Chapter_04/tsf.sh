#!/usr/bin/env bash

LEVEL=/home/james/Documents/llvm-project-main/build

echo $LEVEL

opt -load $LEVEL/lib/LLVMHellok.so -enable-new-pm=0 -hellok < hello.bc > /dev/null

