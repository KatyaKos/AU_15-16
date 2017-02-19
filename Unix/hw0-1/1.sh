#!/bin/bash

ls *.jpg | xargs -I "{}" -P "$(nproc)" convert -colorspace GRAY "{}" "out/{}"
