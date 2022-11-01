#!/bin/bash

#count number of files in working directory
echo "No. of files is $(find "$@" -type f | wc -l)"

#count numnber of files in subdirectories
find . -maxdepth 1 -mindepth 1 -type d | while read dir
do
  echo $dir : $(find "$dir" -type f | wc -l)
done
