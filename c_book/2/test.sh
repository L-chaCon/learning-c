#!/bin/bash

./data/a.out <data/infile.txt >data/outfile.txt

echo "IN:"
./data/printraw <data/stdin
echo "---------------------------"
echo "OUT:"
./data/printraw <data/stdout
