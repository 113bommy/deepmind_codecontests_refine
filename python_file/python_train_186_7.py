# -*- coding: utf-8 -*-
from itertools import accumulate
def inpl(): return map(int, input().split())

N, K, Q = inpl()
A = " " + input()
S = sorted(map(int, A.split()))
ans = S[Q-1] - S[0]
S = S[::-1]

while S:
    s = S.pop()
    A = A.replace(" {} ".format(s), " x ")

    OK = 0
    Que = A.split("x")

    tmp = []
    for q in Que:
        tmp.extend(sorted([int(x) for x in q.split()])[::-1][K-1:])
    if len(tmp) < Q:
        break
    tmp = sorted(tmp)
    ans = min(ans, tmp[Q-1] - tmp[0])

print(ans)