#!/bin/bash

if [ ! -e code/$1 ]; then
    cat model > code/$1
fi