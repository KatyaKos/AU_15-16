#!/bin/bash

while [ 1 = 1 ]
do
	ps -eo comm --sort=-%cpu | head -n 2 | tail -n 1
	sleep 5
done
