N,S = map(int,input().split())
MOD = 998244353
A = list(map(int,input().split()))
dp = [[0 for j in range(S+1)] for i in range(N+1)]
dp[0][0] = 1
for i in range(1, N+1):
	a = A[i-1]
	for j in range(0, S+1):
		if a > j:
			dp[i][j] = 2*dp[i-1][j] % MOD
		else:
			dp[i][j] = (2*dp[i-1][j] + dp[i-1][j-a]) % MOD
print(dp[N][S])