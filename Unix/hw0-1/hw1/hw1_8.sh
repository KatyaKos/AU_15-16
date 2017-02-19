#!/bin/bash

rm output8.txt
cat <input8.txt | sort -R -u >tmp.txt
i=1
while read line
do
	echo "$i     $line" >>output8.txt
	let i=$i+1
done <tmp.txt
rm tmp.txt
