MOD = 10**9 + 7
s = input()
n = len(s)
dp = [0 for _ in range(13)]
dp[0] = 1
for i in range(n):
	dpp = [0 for _ in range(13)]
	if s[i] != "?":
		for j in range(13):
			dpp[(j*10+int(s[i])) % 13] = dp[j]
	else:
		for j in range(13):
			for k in range(10):
				dpp[(j*10+k)%13] += dp[j]
				dpp[(j*10+k)%13] %= MOD
	dp = dpp
print(dp[5])