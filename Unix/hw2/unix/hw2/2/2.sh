#!/bin/bash

draw_space(){
	for i in `seq $1`;
	do
		printf '%s' " "
	done
}

draw_min(){
	for i in `seq $1`;
	do
		printf '%s' "-"
	done
}

draw_line(){
	let p=$1-$2
	let n=2**$p-2
	draw_space $n
	printf '%s' "+"
	let n=$n+1
	draw_min $n
	printf '%s' "o"
	draw_min $n
	printf '%s' "+"

	let p=$2-1
	let m=2**$p
	for i in `seq 2 $m`;
	do
		let p=$1-$2+1
		let n=2**$p-1
		draw_space $n
		printf '%s' "+"
		let p=$p-1
		let n=2**$p-1
		draw_min $n
		printf '%s' "o"
		draw_min $n
		printf '%s' "+"

	done
	echo
	let p=$1-$2
	let n=2**$p-2
	draw_space $n
	printf '%s' "|"
	let m=$m*2
	let p=$p+1
	for i in `seq 2 $m`;
	do
		let n=2**$p-1
		draw_space $n
		printf '%s' "|"
	done
	echo

}

if [ $1 = 1 ]
then
	echo "|"
	echo "o"
fi
if [ $1 -gt 1 ] 
then
	let d=1
	let n=2**$1-2
	draw_space $n
	echo "|"

	while [ $d -ne $1 ]
	do
		draw_line $1 $d
		let d=$d+1
	done

	printf '%s' "o"
	let m=2**$1/2
	for i in `seq 2 $m`;
	do
		draw_space 3
		printf '%s' "o"
	done

fi
echo