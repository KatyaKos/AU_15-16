#!/bin/bash

h=`tput lines`
w=`tput cols`

for (( i = 0; i < $h; i++ )); do
	for (( j = 0; j < $w; j++ )); do
		let t=$RANDOM%3
		if [ $t == 1 ]; then
			let u=$RANDOM%8
			if [ $u == 0 ]; then
				echo -ne "\e[30m*\e[0m" >>tmp.txt
			fi
			if [ $u == 1 ]; then
				echo -ne "\e[31m*\e[0m" >>tmp.txt
			fi
			if [ $u == 2 ]; then
				echo -ne "\e[32m*\e[0m" >>tmp.txt
			fi
			if [ $u == 3 ]; then
				echo -ne "\e[33m*\e[0m" >>tmp.txt
			fi
			if [ $u == 4 ]; then
				echo -ne "\e[34m*\e[0m" >>tmp.txt
			fi
			if [ $u == 5 ]; then
				echo -ne "\e[35m*\e[0m" >>tmp.txt
			fi
			if [ $u == 6 ]; then
				echo -ne "\e[36m*\e[0m" >>tmp.txt
			fi
			if [ $u == 7 ]; then
				echo -ne "\e[37m*\e[0m" >>tmp.txt
			fi
		fi
		if [[ $t == 0 || $t == 2 ]]; then
			echo -n " " >>tmp.txt
		fi
	done
	sleep 0.05
done


