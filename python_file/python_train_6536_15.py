mod = 10 ** 9 + 7
def comb(n, r):
    if n < r:return 0
    if n < 0 or r < 0:return 0
    return fa[n] * fi[r] % mod * fi[n - r] % mod
r1, c1, r2, c2 = map(int, input().split())
fa = [1] * (r2 + c2 + 3)
fi = [1] * (r2 + c2 + 3)
for i in range(1, r2 + c2 + 3):
    fa[i] = fa[i - 1] * i % mod
    fi[i] = pow(fa[i], mod - 2, mod)
def ans(r, c):
    return fa[r + c + 2] * fi[r + 1] * fi[c + 1] % mod - 1
print((ans(r2, c2) - ans(r2, c1 - 1) - ans(r1 - 1, c2) + ans(r1 - 1, c1 - 1)) % mod)