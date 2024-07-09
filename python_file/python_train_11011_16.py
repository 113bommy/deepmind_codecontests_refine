import copy
N,K = map(int,input().split())
A = list(map(int,input().split()))

for i in range(K):
  l = [0]*N
  for i in range(N):
    m,p = i-A[i],i+A[i]
    if p+1 <= N-1:
      l[p+1] -= 1
    if m >= 0:
      l[m] += 1
    if m < 0:
      l[0] += 1
  for i in range(N-1):
    l[i+1] += l[i]
  A = copy.deepcopy(l)
  if A[0] == N:
    break 
print(*A)