#!/usr/bin/env bash

LEVEL=/home/james/Documents/llvm-project-main/build

echo $LEVEL

opt -load $LEVEL/lib/LLVMFnNamePrint.so -enable-new-pm=0 -funcnameprint < test.ll > /dev/null

