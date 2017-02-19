__author__ = 'KatyaKos'

import sys

def preparation(file):
    fin = open(file)
    mass = []
    s = fin.read()
    s = s.lower()
    s = list(map(str, s.split()))
    ans = {}

    for i in s:
        ans.setdefault(i, 0)
        ans[i] += 1

    fin.close()

    return ans

def print_words(file):

    ans = preparation(file)

    s =list(ans.keys())
    s.sort()
    for key in s:
        print(ans[key], key, sep = ' ', end = '\n')

def print_top(file):

    ans = preparation(file)
    s =list(ans.items())
    s.sort(key = lambda item: item[1])

    n = len(s)
    for i in range(min(20, n)):
        print(s[n - i - 1][1], s[n - i - 1][0], sep = ' ')

def main():
    if len(sys.argv) != 3:
        print('usage: ./wordcount.py {--count | --topcount} file')
        sys.exit(1)

    option = sys.argv[1]
    filename = sys.argv[2]
    print_top(filename)
    if option == '--count':
        print_words(filename)
    elif option == '--topcount':
        print_top(filename)
    else:
        print('unknown option: ' + option)
        sys.exit(1)

if __name__ == '__main__':
    main()

"""print('Enter the filename:')
filename = input()
print('Enter the key:')
option = input()

if option == '--count':
    print_words(filename)
elif option == '--topcount':
    print_top(filename)
else:
    print('unknown option: ' + option)"""