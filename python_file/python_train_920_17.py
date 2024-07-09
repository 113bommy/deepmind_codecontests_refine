N,X = map(int,input().split())
A = list(map(int,input().split()))

INF = float('inf')
dp = [[INF]*N for i in range(N+1)]
dp[0] = A[:]

ans = sum(A)
for k in range(N):
    cost = k*X
    if cost > ans: break
    for i in range(N):
        dp[k+1][i] = min(dp[k][i], A[i-k])
    cost += sum(dp[k+1])
    ans = min(ans, cost)

print(ans)