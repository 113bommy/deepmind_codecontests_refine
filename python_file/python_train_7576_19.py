from fractions import gcd
n=int(input())
a=list(map(int,input().split()))
lcm = a[0]
for i in range(1,n):
  lcm = lcm*a[i] // gcd(lcm,a[i])
mod=pow(10,9)+7
ans=0
for x in a:
  ans+=lcm//x
print(ans%mod)