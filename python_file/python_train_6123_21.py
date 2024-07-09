#dpp
import sys
sys.setrecursionlimit(10**7)
MOD = 10**9+7
n = int(input())
dp = [[1 for _ in range(2)] for _ in range(n)]
edges = [[] for _ in range(n)]
for _ in range(n-1):
	x, y = map(int, input().split())
	edges[x-1].append(y-1)
	edges[y-1].append(x-1)

def dfs(le, ro):
	for ed in edges[le]:
		if ed == ro:
			continue
		dfs(ed, le)
		dp[le][0] = (dp[le][0] * (dp[ed][0] + dp[ed][1])) % MOD
		dp[le][1] = (dp[le][1] * dp[ed][0]) % MOD
	return

dfs(0, -1)
print((dp[0][0] + dp[0][1]) % MOD)