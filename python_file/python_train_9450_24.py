D=60
f=lambda:[*map(int,input().split())]
n,k=f()
l=f()
t=[[0]*n for _ in range(D)]
for i in range(n):
  t[0][i]=l[i]-1
for i in range(D-1):
  for j in range(n):
    t[i+1][j]=t[i][t[i][j]]
a=0
for i in range(D):
  if k%2: a=t[i][a]
  k//=2
print(a+1)