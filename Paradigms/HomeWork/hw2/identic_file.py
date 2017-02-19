__author__ = 'KatyaKos'
# !/usr/bin/python

import os
import sys
import hashlib
from collections import defaultdict

def hashfile(filename):
    h = hashlib.sha512()
    with open(filename, "rb") as f:
        chunk_size = 4096
        chunk = f.read(chunk_size)
        while chunk:
            h.update(chunk)
            chunk = f.read(chunk_size)
    return h.digest()

def main():
    if len(sys.argv) != 2:
        print('ERROR! Enter dir name, plz')
        sys.exit(1)

    fnames = defaultdict(list)
    dirname = sys.argv[1]
    for root, dirs, files in os.walk(dirname, topdown=False):
        for name in files:
            #print(os.path.join(root, name))
            if name[0] != '.' and name[0] != '~' and os.path.islink(name) == False:

                h = hashfile(os.path.join(root, name))
                fnames[h].append(os.path.join(root, name))
                """if h in fnames:
                    fnames[h].append(os.path.join(root, name))
                    #print(h, name, sep = '\n')
                    #print(os.path.join(root, name))
                else:
                    fnames[h] = [os.path.join(root, name)]
                    #print(h, name, sep = '\n')"""

    for val in fnames.values():
        if len(val) > 1:
            print(*val, sep = ':')

if __name__ == '__main__':
    main()