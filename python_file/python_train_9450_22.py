N, K = map(int,input().split())

m = 60

A = list(map(int,input().split()))
A = [A[i]-1 for i in range(N)]

D = [A]
for i in range(m):
  temp = []
  for j in range(N):
    temp.append(D[i][D[i][j]])
  D.append(temp)

now = 0
for i in range(m):
  if K >> i&1 == 1:
    now = D[i][now]
print(now+1)