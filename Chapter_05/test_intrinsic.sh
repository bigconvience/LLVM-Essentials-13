#!/bin/bash

clang -emit-llvm -S intrinsic.cpp 

opt -O1 intrinsic.ll -S -o output.ll
