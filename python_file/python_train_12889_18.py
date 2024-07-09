import math

N, W = map(int, input().split())

DP = [[math.inf] * 100001 for _ in range(N+1)]
DP[0][0] = 0
for i in range(1, N+1):
    w, v = map(int, input().split())
    for j in range(100001):
        if j >= v:
            DP[i][j] = min(DP[i-1][j], DP[i-1][j-v]+w)
        else:
            DP[i][j] = DP[i-1][j]

ans = 100000
while DP[N][ans] > W:
    ans -= 1
print(ans)
