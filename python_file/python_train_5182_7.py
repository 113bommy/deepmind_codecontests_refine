import sys

sys.setrecursionlimit(50000)
N,K= [int(v) for v in input().split()]
P = [int(v) - 1 for v in input().split()]
C = [int(v) for v in input().split()]

visited = [True for _ in range(N)]
cycle = []


ans = -float('inf')
for sn in range (N):
    cost = []
    nn = sn
    while True:
        cost.append(C[nn])
        nn = P[nn]
        if sn == nn:
            break
    total = sum(cost)
    l = len(cost)

    t = 0
    for i in range(l):
        t += cost[i]
        if i+1 > K: break
        now = t
        if total > 0:
            e = (K-i-1)//l
            now += total * e
        ans = max(ans,now)


print(int(ans))
