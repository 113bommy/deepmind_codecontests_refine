D=60
n,k,*l=map(int,open(0).read().split())
to=[[0]*n for _ in range(D)]
for i in range(n):
  to[0][i]=l[i]-1
for i in range(D-1):
  for j in range(n):
    to[i+1][j]=to[i][to[i][j]]
a=0
for i in range(D):
  if k%2:
    a=to[i][a]
  k//=2
print(a+1)