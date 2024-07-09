#!/usr/bin/env python3

# input
n, k = map(int, input().split())
p = list(map(int, input().split()))
c = list(map(int, input().split()))
for i in range(n):
    p[i] -= 1

# calc
ans = -int(1e18)
for si in range(n):
    x = si
    s = []
    opscore = 0 
    while True:
        x = p[x]
        opscore += c[x]
        s.append(c[x])
        if x == si: 
            break

    oplen = len(s)
    t = 0 
    for i in range(oplen):
        t += s[i]
        if i+1 > k:
            break
        now = t 
        if opscore > 0:
            e = (k-(i+1))//oplen
            now += opscore * e 
        ans = max(ans, now)

print(ans)
