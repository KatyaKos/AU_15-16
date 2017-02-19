#!/bin/bash

find | perl -pe 's/.*?\//--/g' | perl -pe 's/^-/|/'
