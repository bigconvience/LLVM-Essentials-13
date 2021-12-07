cmake_minimum_required(VERSION 3.20)
project(llvm_ir)

include_directories(/usr/include/llvm)

set(LLVM_CONFIG "-I/usr/include -std=c++14 -fno-exceptions -D_GNU_SOURCE -D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -D__STDC_LIMIT_MACROS -L/usr/lib64 -lLLVM-13")

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${LLVM_CONFIG} -fno-rtti ")

set(CMAKE_CXX_STANDARD 14)

add_executable(llvm_ir
        module.cpp)
