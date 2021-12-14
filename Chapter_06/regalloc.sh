#!/bin/bash

llc test.ll -regalloc=basic -o test0.s
llc test.ll -regalloc=greedy -o test1.s
llc test.ll -regalloc=fast -o test2.s
llc test.ll -regalloc=pbqp -o test3.s

