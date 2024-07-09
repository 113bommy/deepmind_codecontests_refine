n, k = map(int, input().split())
A = list(map(int, input().split()))
for i in range(k):
  C = [0]*(n+1)
  for j in range(n):
    p = max(0, j-A[j])
    q = min(n-1, j+A[j])
    C[p] += 1
    C[q+1] -= 1
  v = 1
  for j in range(n):
    C[j+1]=C[j+1]+C[j]
    if C[j]!=n:
      v = 0
  if v:
    break
  A = C
C = [str(c) for c in C[:-1]]
print(' '.join(C))