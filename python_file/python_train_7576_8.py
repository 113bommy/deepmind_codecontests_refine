from fractions import gcd
N = int(input())
A = list(map(int,input().split()))
mod = 10**9 + 7
LCM = 1
for i in A:
    GCD = gcd(LCM,i)
    LCM = LCM*i//GCD
ans = 0
for i in A:
    ans += LCM//i
print(ans%mod)