#!/bin/bash

find -type f -mtime +1 -mtime -3 \! -name "*.sh" | while read line
do
	a=`basename $line`
	mv -v "$line" "${line/$a/_$a}"
done
