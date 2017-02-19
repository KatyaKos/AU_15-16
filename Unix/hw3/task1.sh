#!/bin/bash

i=0
flag=0
ans=0
n=1

echo "Types:"

sudo dd if=/dev/sda of=MyMBR bs=512 count=1
while read num
do
	if [ $num -ne 0 ]
	then
		flag=1
	fi
	if [ $i = 1 ]
	then
		let "tmp=$num&255"
	fi
	let i=$i+1
	if [ $i = 4 ]
	then
		if [ $flag != 0 ]
		then
			let ans=$ans+1
			echo "Type of $n: $tmp"
		fi
		flag=0
		i=0
		let n=$n+1
	fi
done < <(hexdump -ve '"%d\n"' -s 446 MyMBR) 

echo "Number of not empty: $ans"
sudo rm MyMBR