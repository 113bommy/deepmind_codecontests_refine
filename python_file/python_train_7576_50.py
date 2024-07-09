from fractions import gcd

n = int(input())
a = list(map(int, input().split()))

l = a[0]
for k in a:
  l = ( l * k ) // gcd(l, k)

mod = 10 ** 9 + 7
ans = 0
for k in a:
  ans += l // k

print( int(ans) % mod )
