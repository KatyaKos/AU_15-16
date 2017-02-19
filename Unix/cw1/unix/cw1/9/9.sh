#!/bin/bash

ls -l | awk '{tot+=$5} END {print tot}'
