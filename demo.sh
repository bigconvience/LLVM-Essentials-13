#!/usr/bin/env bash

./clear.sh

clang -S -emit-llvm hello.c
