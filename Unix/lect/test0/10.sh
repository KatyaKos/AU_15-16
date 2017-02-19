#!/bin/bash

i=`cal -N $2 $3 | grep " $1 " | sed -re 's/(..).*/\1/'`
echo $i
