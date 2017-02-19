#!/bin/bash

read line && printf "$line" | grep -Eo "^(<([a-z]+)>[^<]*</\2>|<([a-z]+/)>)$"