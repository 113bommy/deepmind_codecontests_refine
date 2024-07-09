import sys
input = sys.stdin.readline

INF = 10**19
N, K = map(int, input().split())
A = list(map(int, input().split()))
pos = []
neg = []
for a in A:
    if a >= 0:
        pos.append(a)
    else:
        neg.append(a)
pos.sort()
neg.sort()
p, n = len(pos), len(neg)
if K <= p * n:
    lb, ub = -INF, INF
    while ub - lb > 1:
        mid = (lb + ub) // 2
        cnt = 0

        s, t = 0, 0
        while s < p:
            while t < n and pos[s] * neg[t] <= mid:
                t += 1
            cnt += t
            s += 1

        if cnt < K:
            lb = mid
        else:
            ub = mid
    print(ub)
else:
    K -= p * n
    neg = neg[::-1]
    lb, ub = -INF, INF
    while ub - lb > 1:
        mid = (lb + ub) // 2
        cnt = 0

        s, t = p-1, 0
        while s >= 0:
            while t < s and pos[s] * pos[t] <= mid:
                t += 1
            cnt += min(s, t)
            s -= 1

        s, t = n-1, 0
        while s >= 0:
            while t < s and neg[s] * neg[t] <= mid:
                t += 1
            cnt += min(s, t)
            s -= 1

        if cnt < K:
            lb = mid
        else:
            ub = mid
    print(ub)
