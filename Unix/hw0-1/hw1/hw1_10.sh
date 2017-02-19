#!/bin/bash

flag=5
user='kat_kos'

while [ 0 ]
do
	wget -q vk.com/$user
	ans=`grep -c 'profile_time_lv' $user`
	#echo $ans
	if [ "$ans" -ne "$flag" ]
	then

		flag=$ans
		if [ $ans = 1 ]
		then
			echo 'He is offline'
		else
			echo 'He is online'
		fi

	fi
	sleep 30s
	rm $user
done
