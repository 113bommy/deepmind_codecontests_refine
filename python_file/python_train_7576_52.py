from fractions import gcd
mod = pow(10, 9)+7
n = int(input())
A = list(map(int, input().split()))
m = A[0]
for i in range(1, n):
  m = m // gcd(m, A[i]) * A[i]
ans = 0
for i in A:
  ans += m//i
print(ans%mod)