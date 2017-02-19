#!/bin/bash

cat audio.txt | grep -iE '^([0-9a-z_\.\-]*)(\.mp3|\.wav|\.ogg)$'
