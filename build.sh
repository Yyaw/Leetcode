#!/bin/bash

for i in "$*";do
    rfile=${i%.*}
    file=${rfile##*/}
    g++ -g -std=c++11 -o bin/$file $i
done