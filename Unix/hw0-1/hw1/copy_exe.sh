#!/bin/bash

if [ $# -ne 4 ]
then
	echo 'ERROR'
else

	echo $1
	echo $3

	if [[ "$1" = "-i" && "$3" = "-o" ]]
	then
		cp $2 $4
		exit
	else
		if [[ "$1" = "-o" && "$3" = "-i" ]]
		then
			cp $4 $2
			exit
		fi
	fi

	echo 'ERROR'
fi
