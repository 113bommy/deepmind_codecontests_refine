import sys
input = sys.stdin.buffer.readline
mod = 10 ** 9 + 7

def main():
	n, m = map(int, input().split())
	*s, = map(int, input().split())
	*t, = map(int, input().split())
	dp = [[1] * (m + 1)] + [[1] + [0] * m for _ in range(n)]
	for i in range(n):
		for j in range(m):
			dp[i + 1][j + 1] = (dp[i + 1][j] + dp[i][j + 1] - dp[i][j] * (s[i] != t[j])) % mod
	print(dp[n][m])

if __name__ == '__main__':
	main()