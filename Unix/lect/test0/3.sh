#!/bin/bash

cat phone.txt | grep -E '^(?:\+?[0-9]\s?|\+?[0-9]\-?)?([0-9]{3}|\([0-9]{3}\))(\s|\-)?([0-9]{7}|[0-9]{3}(\s|\-)[0-9]{4}|[0-9]{3}((\s|\-)[0-9]{2}){2})$'
