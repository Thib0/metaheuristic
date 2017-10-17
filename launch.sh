#!/bin/sh

mkdir -p out
rm -f out/*.csv

make -B -j8
./mheu
python3 process.py 0
python3 process.py 600
python3 process.py last
