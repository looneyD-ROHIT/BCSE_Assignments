#! /usr/bin/sh

echo "Enter the f_name: \c"
read f_name

if [ -f "$f_name" ]
then
 echo "File found"
 lines=`wc --lines < $f_name`
 echo "Number of lines: $lines"
else
 echo "File not fount. Making a new file anything.txt"
 new_file="anything.txt"
 echo "Hello World!!!\nHello World!!!\nHello World!!!" > $new_file
 echo "Reading new file"
 lines=`wc --lines < $new_file`
 echo "Number of lines: $lines"
fi
