# -*- coding: utf-8 -*-
from collections import deque
h,w = map(int, input().split())
al = [input() for _ in range(h)]

inf = 10**9
m = [[inf]*w for _ in range(h)]
q = deque([])
for hi in range(h):
    for wi in range(w):
        if al[hi][wi]=="#":
            m[hi][wi] = 0
            q.append((hi,wi))

while len(q)>0:
    ch,cw = q.popleft()
    c = m[ch][cw]
    for hi,wi in [[ch+1,cw],[ch,cw+1],[ch-1,cw],[ch,cw-1]]:
        if h>hi>=0 and w>wi>=0 and m[hi][wi]>c+1:
            m[hi][wi] = c+1
            q.append((hi,wi))

res = max([max(m[i]) for i in range(h)])
print(res)