#!/bin/bash

# Translate Verilog -> C++ including testbench
verilator -Wall --trace \
          -cc extend.sv \
          --exe extend.cpp \
          -o Vextend \
          -LDFLAGS "-lgtest -lgtest_main -lpthread"

# Build C++ project with automatically generated Makefile
make -j -C obj_dir/ -f Vextend.mk

# Run executable simulation file
./obj_dir/Vextend