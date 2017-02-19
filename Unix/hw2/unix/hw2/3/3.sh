#!/bin/bash

i=1
echo .
echo

while :
do
	if [ `find . -mindepth "$i" -maxdepth "$i" | wc -l` == 0 ]
	then
		exit
	fi
	find . -maxdepth "$i" -mindepth "$i" | sort | while read "line"
	do
		echo "`basename "$line"`"
	done
	echo
	let "i = i + 1"
done
