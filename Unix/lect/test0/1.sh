#!/bin/bash

echo "010501" | grep -iE "([0-9a-fA-F]{2})\1\1"
