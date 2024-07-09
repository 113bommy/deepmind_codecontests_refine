r1, c1, r2, c2 = map(int, input().split())

n = r2 + c2 + 3
mod = 10 ** 9 + 7
f = [1 for _ in range(n)]
f_inv = [1 for _ in range(n)]
for i in range(1, n):
    f[i] = f[i-1] * i % mod
    f_inv[i] = pow(f[i], mod-2, mod)

def comb(n, k):
    return f[n] * f_inv[k] * f_inv[n-k] % mod
def g(r, c):
    return comb(r+c+2, c+1) - 1

ans = g(r2, c2) - g(r2, c1-1) - g(r1-1, c2) + g(r1-1, c1-1)
ans %= mod

print(ans)