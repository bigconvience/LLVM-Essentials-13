#!/usr/bin/env bash

clang `llvm-config --cxxflags` -fno-rtti -fPIC -shared Hello.cpp -o LLVMHello.so `llvm-config --ldflags`

opt -load LLVMHello.so -hello < hello.bc > /dev/null