N = int(input())
A = sorted([(a, i) for i, a in enumerate(map(int, input().split()))], reverse=True)
dp = [[0]*(N+1) for _ in [0]*(N+1)]

for j, (a, i) in enumerate(A):
    for l in range(j+1):
        r = N-1-(j-l)
        dp[j+1][l] = max(dp[j+1][l], dp[j][l]+a*(r-i))
        dp[j+1][l+1] = max(dp[j+1][l+1], dp[j][l]+a*(i-l))

print(max(dp[N]))
