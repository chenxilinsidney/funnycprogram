#!/bin/sh

# build the program and analyse it with gprop

# gcc
filename="$1"
echo "filename =  $1"
extension=${filename##*.}
echo "extension = $extension"
binaryname=`basename $1 .c`.out
echo "filename =  $binaryname"
if [ "$extension" = "c" ]; then
    echo "compiling $1"
    # gcc -pg $1;
    gcc -pg -o $binaryname $1;
    echo "compiling $1 done"
fi

# execute the program
echo "execute $binaryname in `pwd` and get gmon.out"
./`basename $1 .c`.out > result.txt

# analyse with gprof and write to analyse.txt
gprof $binaryname gmon.out > analyse.txt
