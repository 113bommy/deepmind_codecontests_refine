N,K = map(int,input().split())
A = list(map(int, input().split()))

for k in range(K):
  imos = [0] * (N+1)
  for i, a in enumerate(A):
    l = max(0, i-a)
    r = min(N, i+1+a)
    imos[l] += 1
    imos[r] -= 1
  imos[0] = min(N, imos[0])
  for i in range(N):
    imos[i+1] = min(N, imos[i] + imos[i+1])
  A = imos[:-1]
  if all(a==N for a in A):
    break

print(*A)
  
