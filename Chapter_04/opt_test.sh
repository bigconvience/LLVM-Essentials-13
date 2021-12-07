#!/usr/bin/env bash

opt -O0 -S test.ll > 0.ll
opt -O1 -S test.ll > 1.ll
opt -O2 -S test.ll > 2.ll

