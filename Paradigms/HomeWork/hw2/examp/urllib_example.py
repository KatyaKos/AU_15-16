#!/usr/bin/python3

from urllib.request import urlopen

url = "https://en.wikipedia.org/wiki/Python_(programming_language)"
with urlopen(url) as f:
    for line in f:
        print(line.decode('utf-8'))
