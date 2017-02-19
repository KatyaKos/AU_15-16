#!/usr/bin/python3

# raw strings
s1, s2 = "\\", r"\\"
print(s1, s2)

import re

# basics

# find first location where pattern matches with string
# returns match object

m = re.search(".", "abcd")
print(m.group(0))

m = re.search("1", "abcd")
print(m)

# match against the beginnig of string
m = re.match("1", "123")
print(m.group(0))

m = re.match("2", "123")
print(m)


# full string match
m = re.fullmatch(r"\d+", "123")
print(m.group(0))

m = re.fullmatch("1", "123")
print(m)

m = re.match(r"^\d+$", "123")
print(m.group(0))

# compiled re
c = re.compile(r"^\d+$")
m = c.match("123")
print(m.group(0))

# groups
c = re.compile(r"\+\s*(\d)\s*((?:\d\s*){3})((?:\d\s*){7})")
m = c.match("+79052168692")
print(m.group(0))
print(m.group(1))
print(m.group(2))
print(m.group(3))

m = c.match("+7 905 216 86 92")
print(m.group(0))
print(m.group(1))
print(m.group(2))
print(m.group(3))
