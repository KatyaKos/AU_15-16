#!/bin/bash

cat mac.txt | grep -P -i '^([a-f\d]{2}:){5}[a-f\d]{2}$'
