n = int(input())
a = [int(input()) for _ in range(n)]
suma = sum(a)
suma2 = suma // 2
mod = 998244353

dp1 = [3] + [0] * suma2
dp2 = [3] + [0] * suma2
for ai in a:
    for j in range(suma2, ai - 1, -1):
        dp1[j] = (dp1[j] + dp1[j - ai] * 2) % mod
        dp2[j] = (dp2[j] + dp2[j - ai]    ) % mod
half = dp2[suma2] if suma % 2 == 0 else 0
print(((3 ** n) - sum(dp1) + half + mod) % mod)
