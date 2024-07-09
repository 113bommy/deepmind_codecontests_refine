x,y = map(int,input().split())
if (2*x - y) % 3 != 0 or (2*y-x) % 3 != 0 or 2 * min(x,y) < max(x,y):
    print(0)
    exit()

mod = 10**9 + 7
n = (x+y) // 3
a = (max(x,y)*2 - min(x,y)) // 3

fact = [1]
finv = [1]
for i in range(1, n+1):
    fact += [(fact[i-1] * i) % mod]
    finv += [pow(fact[i], mod-2, mod)]
print((fact[n]*finv[a]*finv[n-a]) % mod)