def cmb(n, r, p):
    return (fac[n] * pow(fac[r], p - 2, p) * pow(fac[n - r], p - 2, p)) % p


p = 998244353
N, M, K = map(int, input().split())
fac = [1] * (max(N, M) + 1)
for i in range(1, max(N, M) + 1):
    fac[i] = (fac[i - 1] * i) % p

ans = 0
for k in range(K + 1):
    ans += M * pow(M - 1, N - k - 1, p) * cmb(N - 1, k, p)
    ans %= p
print(ans)
