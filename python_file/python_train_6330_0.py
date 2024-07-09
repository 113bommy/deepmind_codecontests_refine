import sys

n = int(input())
aaa = list(map(int, sys.stdin))
MOD = 998244353

s = sum(aaa)
dp1 = [0] * (s + 1)
dp2 = [0] * (s + 1)
dp1[0] = 1
dp2[0] = 1
tmp_sum = 0
for a in aaa:
    for i in range(tmp_sum, -1, -1):
        dp1[i + a] += dp1[i]
        dp1[i] *= 2
        dp2[i + a] += dp2[i]
    for i in range(tmp_sum, -1, -1):
        dp1[i] %= MOD
        dp2[i] %= MOD
    tmp_sum += a

h = (s + 1) // 2
ans = (pow(3, n, MOD) - sum(dp1[h:]) * 3) % MOD
if s % 2 == 0:
    ans = (ans + dp2[h] * 3) % MOD
print(ans)
