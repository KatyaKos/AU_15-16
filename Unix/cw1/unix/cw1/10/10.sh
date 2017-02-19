#!/bin/bash

printf -- "`base64 -- "$1"`" > "$1"