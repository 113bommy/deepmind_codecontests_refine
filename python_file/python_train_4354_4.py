n = int(input())
a = list(map(int, input().split()))

dp = [[0 for _ in range(n+1)] for _ in range(n+1)]
#dp[l][r]: 左l個右r個取ったところからの前-後max
for i in range(n):
	dp[i][n-1-i] = a[i]
for x in range(n-2, -1, -1):
	for y in range(x+1):
		l, r = y, x-y
		dp[l][r] = max(-dp[l+1][r] + a[l], -dp[l][r+1] + a[-(r+1)])

print(dp[0][0])