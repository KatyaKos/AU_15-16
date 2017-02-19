#!/bin/bash

transfer(){

	#echo "$1 $2 $3 $4"
	if [ $4 -eq 1 ]
	then
		echo "$1 to $2"
	else
		let tmp=$4-1
		transfer $1 $3 $2 $tmp
		echo "$1 to $2"
		let tmp=$4-1
		transfer $3 $2 $1 $tmp
	fi
}

transfer 1 3 2 $1