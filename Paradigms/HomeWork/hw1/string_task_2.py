__author__ = 'KatyaKos'

def verbing(s):
    n = len(s)
    if n >= 3:
        if s[n - 3:] == 'ing':
            return s + 'ly'
        else:
            return s + 'ing'
    return s

def not_bad(s):
    if 'not' in s and 'bad' in s:
        i, j = s.index('not'), s.index('bad')
        if j > i:
            return s[:i] + 'good' + s[j + 3:]

def get_front(s):
    return s[:len(s) // 2 + len(s) % 2]

def get_back(s):
    return s[len(s) // 2 + len(s) % 2:]

def front_back(s1, s2):
    return get_front(s1) + get_front(s2) + get_back(s1) + get_back(s2)

print('String to change with "ing"/"ly":')
s1 = input()
print('String to change for good:')
s2 = input()
print('Strings to merge:')
s3 = input()
s4 = input()

s = verbing(s1)
print('"ing"/"ly" string: ', s)

s = not_bad(s2)
print('Bad for good: ', s)

s = front_back(s3, s4)
print('Merged front/back: ', s)