import sys
input = sys.stdin.buffer.readline
MOD = 10**9+7

MAXN = 2*10**5+5
f = [1]
for i in range(MAXN):
    f.append(f[-1] * (i+1) % MOD)
def nCr(n, r, mod=MOD):
    return f[n] * pow(f[r], mod-2, mod) * pow(f[n-r], mod-2, mod) % mod

n, k = map(int, (input().split()))
ans = 0
for m in range(min(n-1,k)+1):
    ans += nCr(n,m) * nCr(n-1, n-m-1) % MOD
    ans %= MOD
print(ans)
