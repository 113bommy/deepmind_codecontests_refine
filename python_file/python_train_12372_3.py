n=int(input())
l=[list(map(int,input().split()))    for _ in range(n)]

def chk():
  v=0
  for j in range(n):
    for i in range(n):
      f=True
      for k in range(n):
        if l[i][j]>l[i][k]+l[k][j]:
          return -1
        if l[i][j]==l[i][k]+l[k][j] and i!=k and k!=j:
          f=False
      if f:v+=l[i][j]
  return v//2
print(chk())