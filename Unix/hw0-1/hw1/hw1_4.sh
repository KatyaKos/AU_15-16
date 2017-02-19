#!/bin/bash -i

if [ $# = 0 ]
then
	echo 'ERROR'
else
	history | grep -oE "\s+$1(\n|\s|\$)"| wc -l
fi
