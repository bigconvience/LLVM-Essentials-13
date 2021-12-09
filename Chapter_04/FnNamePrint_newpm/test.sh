#!/usr/bin/env bash

LEVEL=/home/james/Documents/llvm-project-main
FILE=FnNamePrint.h

echo $LEVEL

cp $FILE $LEVEL/llvm/include/llvm/Transforms/Utils/$FILE

SOURCE=FnNamePrint.cpp
cp $SOURCE $LEVEL/llvm/lib/Transforms/Utils/$SOURCE

$LEVEL/build/bin/opt ../test.ll -passes=funcnameprint
