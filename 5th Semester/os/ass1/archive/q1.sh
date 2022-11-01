#! /usr/bin/sh

echo "Enter the value of uv1: \c"
read uv1
echo "Enter value of uv2: \c"
read uv2
echo "(a)"
echo "(i) --> \c"
echo "$uv1, $uv2"
echo "(ii) --> \c"
echo "$uv1 and $uv2"
echo "(b) --> \c"
reverse=`echo $uv1 | rev`
echo $reverse

