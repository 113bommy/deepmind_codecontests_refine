N, S = map(int, input().split())
A = list(map(int, input().split()))
mod = 998244353
L = [[0 for i in range(S+1)] for j in range(N+1)]
L[0][0] = 1
for j, a in enumerate(A):
  for i in range(S+1):
    if i < a:
      L[j+1][i] = (2 * L[j][i]) % mod
    else:
      L[j+1][i] = (2 * L[j][i] + L[j][i-a]) % mod
print(L[N][S])