def main():
	N, K = map(int, input().split())
	DIV = 10**9+7
	sqrtn = int(N**0.5)
	ans = 1
	s = []
	for i in range(1, sqrtn+1):
		s.append(i)
		if i < N//i:
			s.append(N//i)
	s.sort()

	r = []
	for i in range(len(s)-1):
		left = N//s[i+1]
		right = N//s[i]
		r.append(right-left)
	r.append(1)

	m = len(s)
	mp = {}
	for i in range(m):
		mp[s[i]] = i

	dp = [[0 for _ in range(m)] for _ in range(K+1)]
	dp[0][mp[N]] = 1
	for i in range(K):
		for j in range(m-2, -1, -1):
			dp[i][j] += dp[i][j+1]
			dp[i][j] %= DIV
		for j in range(m):
			nj = mp[N//s[j]]
			dp[i+1][j] += dp[i][nj]*r[j]%DIV
			dp[i+1][j] %= DIV

	ans = 0
	for j in range(m):
		ans += dp[K][j]
		ans %= DIV
	print(ans)


if __name__ == '__main__':
	main()