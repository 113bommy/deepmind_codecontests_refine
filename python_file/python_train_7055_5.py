n, m = map(int, input().split())
mod = pow(10, 9)+7
ans = 0
a = 1
b = 1
c = 1
for i in range(m-n+1, m+1):
  b *= i
  b %= mod
for i in range(n+1):
  k = -1 if i%2 else 1
  ans += k*a*b**2*c
  ans %= mod
  a *= m-i
  a %= mod
  b *= pow(m-i, mod-2, mod)
  b %= mod
  c *= n-i
  c *= pow(i+1, mod-2, mod)
  c %= mod
print(ans)