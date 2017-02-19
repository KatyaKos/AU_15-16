#!/bin/bash

a=`echo "$1" | rev`
if [ "$1" == "$a" ]
then
	echo 'YES'
else
	echo 'NO'
fi
