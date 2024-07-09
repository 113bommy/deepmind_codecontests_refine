n, k = map(int, input().split())
P = tuple(map(lambda x: int(x)-1, input().split()))
C = tuple(map(int, input().split()))
from collections import deque
ans = -2*10**9
for idx, root in enumerate(P):
    scores = [C[root]]
    p = P[root]
    while True:
        scores.append(scores[-1] + C[p])
        p = P[p]
        if p == root:
            break

    sc = scores[-1]
    if sc <= 0:
        if k < len(scores):
            ans = max(ans, max(scores[:k]))
        else:
            ans = max(ans, max(scores))
    else:
        kk, r = divmod(k, len(scores))
        if r == 0:
            ans = max(ans, kk*sc, (kk-1)*sc + max(scores))
        else:
            ans = max(ans, kk*sc + max(scores[:r]))
print(ans)
