N, M, K = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

a,b=[0],[0]
for i in range(N):
  a.append(a[i] + A[i])
for i in range(M):
  b.append(b[i] + B[i])
ans = 0
j = 0
for i in range(N + 1): 
  if a[i]>K:
    break
  while b[j] > K - a[i]:
    j -= 1
    ans = max(ans, i + j)
print(ans)