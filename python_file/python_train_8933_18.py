n, a, b, k = map(int, input().split())

mod = 998244353
fact = [1] + [0] * n
inv_fact = [0] * (n+1)
for i in range(n):
    fact[i+1] = (fact[i] * (i+1)) % mod

for i in range(n+1):
    inv_fact[i] = pow(fact[i],mod-2,mod)
    
def cb(n, k, mod):
    return (fact[n] * inv_fact[k] * inv_fact[n-k]) % mod

ans = 0
for x in range(n+1):
    if (k-x*a) % b == 0:
        y = (k-x*a)//b
        if y >= 0:
            if x > n or y > n:
                pass
            else:
                ans += cb(n, x, mod) * cb(n, y, mod)
                ans %= mod
    
print(ans)
