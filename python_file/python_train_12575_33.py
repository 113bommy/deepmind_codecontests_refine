import sys

N = int(sys.stdin.readline())
S = sys.stdin.readline().strip()

ans = 0
for L in range(1, N):
	dp = [0]*N 
	for x in range(N - L):
		if S[x] == S[x+L]:
			if x==0: dp[x] += 1
			else: dp[x] = min(dp[x-1]+1, L)
			ans = max(ans, dp[x])
print(ans)