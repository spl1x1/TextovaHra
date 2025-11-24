#!/bin/bash

cmake build -S .. -B .
make
./ItemTest
