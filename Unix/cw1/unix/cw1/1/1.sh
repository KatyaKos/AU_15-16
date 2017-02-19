#!/bin/bash

read line && printf "$line" | grep -Eo "^([A-Za-z0-9]|_|\-|\.|,)*[A-Za-z]([A-Za-z0-9]|_|\-|\.|,)*@[A-Za-z]+(\.[A-Za-z]*)+$"