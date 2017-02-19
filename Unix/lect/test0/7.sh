#!/bin/bash

fin="zytat.txt"
name=`head -n 1 $fin`
n=`head -n 2 $fin | tail -n 1`
let i=$RANDOM%$n
let i=$i+1
str="* $i"


flag=0

while read line
do
	#echo "$line"
	#echo "$str"
	if [ $flag -eq 1 ]
	then
		if [ "$line" == '\*[0-9]+' ]
		then
			flag=0
		else
			echo "$line"
		fi
	fi
	if [ "$line" = "$str" ]
	then
		flag=1
	fi
		
done <$fin

echo "($name)"
