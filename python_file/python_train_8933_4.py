MOD = 998244353
n, a, b, k = [int(item) for item in input().split()]

fac = [1] + [0] * n
fac_inv = [1] + [0] * n
for i in range(1, n+1):
    fac[i] = fac[i-1] * (i) % MOD
    fac_inv[i] = fac_inv[i-1] * pow(i, MOD-2, MOD) % MOD

def mod_nCr(n, r):
    if n == 0 and r == 0:
        return 1
    if n < r or n < 0:
        return 0
    tmp = fac_inv[n-r] * fac_inv[r] % MOD
    return tmp * fac[n] % MOD 

if a < b:
    a, b = b, a
max_a_num = k // a + 1
ans = 0
for a_num in range(max_a_num):
    lest = k - (a_num * a)
    if lest % b != 0 or lest < 0:
        continue
    b_num = lest // b
    ans += mod_nCr(n, a_num) * mod_nCr(n, b_num)
    ans %= MOD
print(ans)