#!/bin/sh

#counting the occurence of a word in a file
read -p "Enter the file name :- " file_path
read -p "Enter the word to analysed :- " word

#gettting the total word count
word_count=$(grep -w -o -n $word $file_path | wc -l)

if [ "$word_count" -gt 0 ]; then #print the total word count
	echo "Total word count :- $word_count"
else #case for word count = 0
	echo "Word Not Found !"
	exit
fi

#count the occurence of word in each line of the file 
count=0
for i in $(grep -w -o -n $word $file_path | cut -d : -f 1 | uniq -c)
do
    if [ "$count" -eq 0 ]
    then
        count=$i
    else
        echo "line $i -> $count" #print the count of occurence of the word in the file
        count=0
    fi
done
