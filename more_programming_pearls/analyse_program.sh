#!/bin/sh

# build the program and analyse it with gprop

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
    gcc -pg -fprofile-arcs -ftest-coverage -o $binaryname $1 -lm;
    echo "compiling $1 done"
fi

# execute the program
echo "execute $binaryname in `pwd` and get gmon.out"
binaryresult="$programname"_result.txt
./`basename $1 .c`.out > "$binaryresult"
echo "execute result saved in $binaryresult"

# analyse with gprof and write to analyse.txt
echo "analyse $binaryname in `pwd` with gprof"
gprofresult="$programname"_gprof_result.txt
gprof $binaryname gmon.out > "$gprofresult"
echo "gprof result saved in $gprofresult"

# analyse with gcov and create .gcov files
echo "analyse $binaryname in `pwd` with gcov"
gcov -b $filename 

# analyse with time
echo "analyse $binaryname in `pwd` with time"
time -p ./`basename $1 .c`.out > "$binaryresult"
