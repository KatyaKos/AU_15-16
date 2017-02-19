#!/usr/bin/python3

from collections import deque

d = deque()
d.appendleft(1)
d.append(2)
d.append(3)
print(d)
print(d.popleft())
print(d.pop())

d = deque(maxlen = 2)
for i in range(10):
    d.append(i)
    print(d)

from collections import namedtuple
Point = namedtuple('Point2D', ['x', 'y'])
p = Point(1, 2)
print(p)
p = Point(x = 1, y = 2)
print(p[0], p[1])
print(p.x, p.y)

Item = namedtuple('Item', ['word', 'cnt'])
d = {"one": 1, "two": 2, "three": 3}
for item in map(Item._make, d.items()):
    print(item)

from collections import Counter

xs = [1, 2, 1, 3, 4, 2, 3]
c = Counter(xs)
print(c.most_common())
c.update([1, 1, 1, 1, 2, 2, 2, 3, 3, 4])
print(c.most_common())

from collections import defaultdict

d = defaultdict(int)
print(d[0], d[1], d[2])
d[0] += 3
d[1] += 2
d[2] += 1
print(d[0], d[1], d[2])

d = defaultdict(list)
print(d[0])
d[0].append(0)
print(d[0])
