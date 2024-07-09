from heapq import heappush, heappop

n = int(input())
A = list(map(int, input().split()))

MX = 2005
f_inf = float('inf')
dp = [[0 for _ in range(MX)] for _ in range(MX)]
dp[0][0] = 0

hq = []
for i in range(n):
    heappush(hq, (-A[i], i))

ans = 0
for i in range(n):
    x, pi = heappop(hq)
    for l in range(i+1):
        r = i-l
        dp[i+1][l+1] = max(dp[i+1][l+1], dp[i][l] + (pi-l)*A[pi])
        dp[i+1][l] = max(dp[i+1][l], dp[i][l] + ((n-r-1)-pi)*A[pi])

ans = 0
for i in range(n+1):
    ans = max(ans, dp[n][i])
print(ans)