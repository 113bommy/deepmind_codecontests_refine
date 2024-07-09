def choose(n,a,mod):
    x, y = 1, 1
    for i in range(a):
        x = x * (n - i) % mod
        y = y * (i + 1) % mod
    return x * pow(y, mod - 2, mod) % mod

k = int(input())
n = len(input())
mod = pow(10,9)+7
start = 1
ans = start*pow(26,k,mod)
for i in range(1,k+1):
    start *= (i+n-1)*pow(i,mod-2,mod)
    start %= mod
    ans += (start*pow(25,i,mod)*pow(26,k-i,mod))
    ans %= mod
print(ans)