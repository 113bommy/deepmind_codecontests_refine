MOD = 10 ** 9 + 7
fac = [1] * (10 ** 5 + 10)
for i in range(len(fac) - 1):
    fac[i + 1] = fac[i] * (i + 1) % MOD


def comb(n, k):
    if k < 0 or k > n:
        return 0
    return fac[n] * pow(fac[n - k], MOD - 2, MOD) * pow(fac[k], MOD - 2, MOD) % MOD


n = int(input())
a = list(map(int, input().split()))
d = [-1] * n
for i, x in enumerate(a):
    if d[x - 1] != -1:
        p = d[x - 1]
        q = i
    else:
        d[x - 1] = i
print(n)
for k in range(2, n + 2):
    ans = 0
    ans += comb(n - 1, k - 2)
    ans += comb(n - 1, k - 1) * 2 - comb(p + n - q, k - 1)
    ans += comb(n - 1, k)
    print(ans % MOD)
