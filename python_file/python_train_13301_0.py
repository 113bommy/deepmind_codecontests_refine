#!/usr/bin/env python3

R, C, K = list(map(int, input().split()))

V = [[] for i in range(R)]
for i in range(K):
    r, c, v = list(map(int, input().split()))
    V[r-1].append([c, v])


# dp = [[[0 for j in range(R+1)] for i in range(C+1)]

# print(rck)
dp = [0] * (C+1)
for r in range(1, R+1):
    tmp0 = 0
    tmp1 = 0
    tmp2 = 0
    tmp3 = 0
    V[r-1].sort()
    for c, v in V[r-1]:
        tmp0 = max(dp[c], tmp0)
        tmp1 = max(dp[c], tmp1)
        tmp2 = max(dp[c], tmp2)
        tmp3 = max(dp[c], tmp3)

        tmp3 = max(tmp3, tmp2+v)
        tmp2 = max(tmp2, tmp1+v)
        tmp1 = max(tmp1, tmp0+v)

        dp[c] = max(tmp0, tmp1, tmp2, tmp3)
    for i in range(1, C+1):
        dp[i] = max(dp[i], dp[i-1])
    # print(dp)

print(dp[-1])
