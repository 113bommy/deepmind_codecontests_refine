MOD = 10**9+7
MAXN = 5*(10**5)+5
f = [1]
for i in range(MAXN):
    f.append(f[-1] * (i+1) % MOD)
def nCr(n, r, mod=MOD):
    return f[n] * pow(f[r], mod-2, mod) * pow(f[n-r], mod-2, mod) % mod

def nPr(n, r, mod=MOD):
    return f[n] * pow(f[n-r], mod-2, mod) % mod

n, m = map(int, input().split())
ans = 0
for k in range(n+1):
    # tmp = pow(nPr(m-k, n-k), 2, MOD) * nPr(m, k) * nCr(n,k) % MOD
    tmp = nPr(m-k, n-k) * nPr(m, n) * nCr(n,k) % MOD
    if k%2:
        ans -= tmp
    else:
        ans += tmp
ans = (ans + MOD) % MOD
print(ans)
