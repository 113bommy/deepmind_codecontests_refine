#imsosorryididntwanttoimplementmodpow
import math
n,m = [int(x) for x in input().split()]

def comb(n, r):
    return math.factorial(n) // (math.factorial(n-r)*math.factorial(r))

i = 2
ans = 1
while (i<=m):
    if m%i==0:
        mult = 0
        while (m%i==0):
            mult += 1
            m //= i
        ans *= comb(n+mult-1,n-1)
    i += 1
if m!=1:
    ans *= comb(n,n-1)

print(ans%int(1e9+7))
