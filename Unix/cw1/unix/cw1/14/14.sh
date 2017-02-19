#!/bin/bash

if [[ $# == 1 ]]
then
	echo hi
	if [[ "$1" == "-d" || "$1" == "--date" ]]
	then
		watch -n 1 date
	fi
fi
if [[ $# == 0 ]]
then
	watch -n 1 "date | grep -Eo "[0-9]{2}:[0-9]{2}:[0-9]{2}""
fi