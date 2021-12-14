#!/usr/bin/env bash

llc --version | grep Default

llc -mtriple=x86_64-unknow-linux-gnu -verify-machineinstrs hadd.ll
