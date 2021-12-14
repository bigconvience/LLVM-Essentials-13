#!/bin/bash

llc --print-after-isel test.ll > outfile 2>&1
