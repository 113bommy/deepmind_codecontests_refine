K = int(input())
S = input()
N = len(S)

MOD = 10 ** 9 + 7

# 逆元を利用してcomb(nCk)をO(1)計算
# https://qiita.com/ophhdn/items/5622ac22cce8fc9432bf
n = N + K + 3
fac = [1] * (n + 1) 
inv = [1] * (n + 1)
for j in range(1, n + 1):
    fac[j] = (fac[j - 1] * j) % MOD

inv[n] = pow(fac[n], MOD-2, MOD)
for j in range(n - 1, -1, -1):
    inv[j] = (inv[j + 1] * (j + 1)) % MOD

def comb(n, r):
    if r > n or n < 0 or r < 0:
        return 0
    return (fac[n] * inv[n - r] * inv[r]) % MOD

ans = 0
for i in range(K + 1):
  p = comb(N + K - i - 1, N - 1) * pow(26, i, MOD) * pow(25, K - i, MOD) % MOD
  ans += p
  ans %= MOD
  
print(ans)