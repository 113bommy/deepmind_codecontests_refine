from math import sqrt
n, k = map(int, input().split())
MOD = 10**9 + 7
max1 = int(sqrt(n))
dp1 = [[0 for _ in range(max1+1)] for _ in range(k)]
for j in range(1, max1+1):
	dp1[0][j] = 1
max2 = int(n/(max1+1))
dp2 = [[0 for _ in range(max2+1)] for _ in range(k)]
for j in range(1, max2+1):
	dp2[0][j] = int(n/j) - int(n/(j+1))

for i in range(k-1):
	csum1 = (sum(dp1[i])+sum(dp2[i])) % MOD
	dp1[i+1][1] = csum1
	for j in range(2, max1+1):
		dp1[i+1][j] = (dp1[i+1][j-1] - dp2[i][j-1]) % MOD
	csum2 = sum(dp1[i][:max2+1]) % MOD
	dp2[i+1][max2] = (csum2*dp2[0][max2]) % MOD
	for j in range(max2-1, 0, -1):
		csum2 -= dp1[i][j+1]
		csum2 %= MOD
		dp2[i+1][j] = (csum2*dp2[0][j]) % MOD

print((sum(dp1[k-1])+sum(dp2[k-1]))%MOD)