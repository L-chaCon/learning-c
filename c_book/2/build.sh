#!/bin/bash

if ! [[ $1 ]]; then
  echo "Put a excersise number"
  exit
fi

cc $1.c -o data/a.out
echo "$1.c was build"
