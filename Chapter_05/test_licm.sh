#!/usr/bin/env bash


opt -licm licm.ll -o licm.bc
llvm-dis licm.bc -o licm_opt.ll
cat licm_opt.ll
