#!/bin/bash           

echo -n 1>output.txt
while read line           
do
	a=`factor $line`
	echo -e $a 1>>output.txt

          
done <input.txt 
