#!/bin/bash

grep '^#include' file.c | sed -e 's/#include [<"]//;s/[">]//'
