import fractions
  
N = int(input())
A = list(map(int, input().split()))

ans = 0
MOD = 10**9 + 7

LCM = A[0]
for i in range(1, N):
    LCM *= A[i]//fractions.gcd(LCM, A[i])
    
for a in A:
  ans += LCM//a
  
print(ans%MOD)