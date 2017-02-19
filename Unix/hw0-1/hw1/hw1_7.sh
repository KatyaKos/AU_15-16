#!/bin/bash

let a=$RANDOM%100 #Больше 100 ждать уж очень долго:(
#echo $a
dd if=/dev/urandom of=rnd.txt bs=1M count=1
