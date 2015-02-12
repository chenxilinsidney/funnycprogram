#!/bin/sh

# build the c source file with gcc

# gcc
filename="$1"
echo "filename =  $1"
extension=${filename##*.}
echo "extension = $extension"
programname=`basename $1 .c`
echo "programname =  $programname"
binaryname=`basename $1 .c`.out
echo "binaryname =  $binaryname"
if [ "$extension" = "c" ]; then
    echo "compiling $1"
    # if want to debug add -g
    # -pg for gprof
    # -fprofile-arcs -ftest-coverage for gcov
    # -Wall for warnings
    gcc -Wall -o $binaryname $1 heap.c -lm;
    echo "compiling $1 done"
fi
