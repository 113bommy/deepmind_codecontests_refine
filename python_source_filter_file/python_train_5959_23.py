from math import *

n, m, k = map(int, input().split())
a = []
for i in range(k):
    a.append([int(i) for i in input().split()])
b = []
for i in range(k):
    b.append([int(i) for i in input().split()])

c = []
for i in range(k):
    c.append([b[i][0] - a[i][0], b[i][1] - a[i][1]])


s = (n-1)*'L' + (m-1)*'U'
ci = 0
for i in range(m):
    if ci == 0:
        s += 'R'*(n-1)
    else:
        s += 'L'*(n-1)
    ci = 1 - ci
    s += 'D'

print(len(s))
print(s)
