N,K = map(int, input().split())
A = list(map(int, input().split()))

for cnt in range(K):
  B = [0] * (N+1)
  for i in range(N):
    bright = A[i]
    l = max(i-bright,0)
    r = min(i+bright+1, N)
    B[l] += 1
    B[r] -= 1
  for i in range(N):
    B[i+1] += B[i]
  
  A = B[:-1]
  #print(A)
  if min(A) == N:
    #print(cnt)
    break
    
print(" ".join(map(str,A)))

