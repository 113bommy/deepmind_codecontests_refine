N,M = map(int,input().split())
A = set([int(input()) for _ in range(M)])
dp = [0]*(N+1)
dp[0] = 1
for i in range(1,N+1):
    dp[i] = (dp[i-1] + dp[i-2])%(1000000007)
    if i in A:dp[i] = 0
    
print(dp[N])