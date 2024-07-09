from fractions import gcd
N = int(input())
A = list(map(int,input().split()))
lcm = A[0]
for i in range(1,N):
    lcm = (lcm*A[i])//gcd(lcm,A[i])

MOD = 10**9+7
ans = 0
for a in A:
    b = lcm//a
    ans += b
print(ans%MOD)