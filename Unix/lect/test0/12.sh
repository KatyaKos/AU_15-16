#!/bin/bash

str=$1
n=${#str}

for i in $(seq $n)
do
	ch=${str:$i-1:1}
	code=`LC_CTYPE=C printf '%d' "'$ch"`
	let code=$code+1
	printf "\\$(printf '%03o' "$code")"
done

echo

