#!/bin/bash  

mkdir -p /workspaces/TextovaHra/build
cd /workspaces/TextovaHra/build
cmake build -S .. -B .
make
./TextovaHra
