n,m=map(int,input().split())
A=[[0]*m for i in range(n)]
for i in range(n):
  A[i]=list(map(int,input().split()))
B=[0]*m
for i in range(n):
  B[A[i][0]-1]+=1
a=0
b=0
for i in range(m):
  if B[i]>a:
    a=B[i]
    b=i
ans=a
C=[b+1]
i=0
while i<=m-2:
  B=[0]*m
  for j in range(n):
    for k in range(m):
      if A[j][k] not in C:
        B[A[j][k]-1]+=1
        break
  a=0
  b=0
  for l in range(m):
    if B[l]>a:
      a=B[l]
      b=l
  if ans>a:
    ans=a
  C.append(b+1)
  i=i+1
print(ans)