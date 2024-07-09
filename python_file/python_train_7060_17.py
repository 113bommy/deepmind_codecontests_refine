# -*- coding: utf-8 -*-
from bisect import bisect, bisect_left
from itertools import accumulate, product

N = int(input())
A = list(map(int, input().split()))
S = list(accumulate(A))
T = sum(A)
ans = 10**16

for j in range(1, N-1):
    PQ = S[j]
    RS = T - S[j]
    #print("PQ RS", PQ, RS)
    
    i1 = bisect(S, PQ/2) - 1
    i2 = bisect_left(S, PQ/2)
    
    k1 = bisect(S, RS/2 + PQ) - 1
    k2 = bisect_left(S, RS/2 + PQ)
    
    for i, k in product([i1, i2], [k1, k2]):
        #print(i, j, k)
        if i < 0 or i==j or j == k or k == N-1:
            continue
        PQRS = [S[i], S[j] - S[i], S[k] - S[j], T - S[k]]
        #print(PQRS)
        ans = min(ans, abs(max(PQRS) - min(PQRS)))

print(ans)