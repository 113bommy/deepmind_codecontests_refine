n, k = map(int, input().split())
A = list(map(int, input().split()))

for i in range(1, 100):
  imos = [0] * (n + 1)
  for j in range(n):
    imos[max(0, j - A[j])] += 1
    imos[min(n, j + A[j] + 1)] -= 1
  
  nA = [0] * n
  nA[0] = imos[0]
  for j in range(1, n):
    nA[j] = nA[j - 1] + imos[j]

  A = nA[:]
  if i >= k:
    break

print(*A)