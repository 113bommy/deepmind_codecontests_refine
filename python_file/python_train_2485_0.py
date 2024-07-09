N, X, Y, Z = map(int, input().split())
p = 10 ** 9 + 7
m = 1
m <<= X
m += 1
m <<= Y
m += 1
m <<= Z - 1
L = 2 ** (X + Y + Z - 1)
M = [[0 for _ in range(10)] for _ in range(L)]
for i in range(L):
  for j in range(10):
    k =  i << (j + 1)
    k += 1 << j
    M[i][j] = (k % L) if k & m != m else -1
DP = [[0 for _ in range(L)] for _ in range(N + 1)]
DP[0][0] = 1
for i in range(N):
  for j in range(L):
    if DP[i][j] == 0:
      continue
    DP[i][j] %= p
    for k in range(10):
      l = M[j][k]
      if l < 0:
        continue
      DP[i + 1][l] += DP[i][j]
cnt = 10 ** N % p
print((cnt - sum(DP[N]) % p) % p)