#!/bin/bash

a="0"
b="1"
c=""

read n

for i in `seq 1 "$n"`;
do
	c="`bc <<< "$a + $b"`"
	a="$b"
	b="$c"
done

echo -e "$a" | tr -d '\\\n'
echo