#!/bin/bash

find "$1" -mindepth 1 -size -100c | xargs tar -czf "$1".tar.gz