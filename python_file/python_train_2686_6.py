import sys
input = sys.stdin.readline

p = int(input())
A = tuple(map(int, input().split()))
B = [0]*p
U = p-1
MOD = p
 
fact = [1]*(U+1)
fact_inv = [1]*(U+1)
 
for i in range(1,U+1):
    fact[i] = (fact[i-1]*i)%MOD
fact_inv[U] = pow(fact[U], MOD-2, MOD)
 
for i in range(U,0,-1):
    fact_inv[i-1] = (fact_inv[i]*i)%MOD

def comb(n, k):
    if k < 0 or k > n:
        return 0
    z = fact[n]
    z *= fact_inv[k]
    z %= MOD
    z *= fact_inv[n-k]
    z %= MOD
    return z

for j, a in enumerate(A):
  if a:
    B[0] += 1
    temp = 1
    for i in range(p-1, -1, -1):
      B[i] -= (-1)**(i%2) * temp * comb(p-1, i)
      temp *= j
      temp %= p
      B[i] %= p
print(*B)