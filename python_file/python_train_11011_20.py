N, K = map(int, input().split())
A = list(map(int, input().split()))
 
 
for k in range(K):
  B = [0]*N
  for i in range(N): 
    start = max(0, i-A[i])
    end = min(N, i+A[i]+1)
    B[start] += 1
    if end <= N - 1:
      B[end] -= 1
 
  for i in range(1, N):
    B[i] = B[i-1] + B[i] 
  A = B
  if min(A) == N:
    break
 
print(*A)