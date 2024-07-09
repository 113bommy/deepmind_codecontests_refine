n, A, B, k = list(map(int, input().split()))

MOD = 998244353
MAX = n+2

fact, inverse = [0]*(MAX), [0]*(MAX)
fact[0], inverse[0] = 1, 1
for i in range(1, MAX):
  fact[i] = (fact[i-1]*i)%MOD
  inverse[i] = pow(fact[i], MOD-2, MOD)

def mod_comb(n, r):
  if n<r or n==0: return 0
  if r==0: return 1
  return (((fact[n]*inverse[r])%MOD)*inverse[n-r])%MOD

ans = 0
for i in range(n+1):
  if (k-A*i)%B == 0:
    b = (k-A*i)//B
    if 0<=b<=n:
      ans = (ans+mod_comb(n, i)*mod_comb(n, b))%MOD

if ans==0:
  print(1)
else:
  print(ans)