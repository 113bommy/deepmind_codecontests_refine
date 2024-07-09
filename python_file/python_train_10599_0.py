mod=10**9+7

def calc(mat1,mat2):
  n=len(mat1)
  ret=[[0]*n for _ in range(n)]
  for i in range(n):
    for j in range(n):
      for k in range(n):
        ret[i][j]+=mat1[i][k]*mat2[k][j]
        ret[i][j]%=mod
  return ret

n,k=map(int,input().split())
tmp=[[0]*n for _ in range(n)]
for i in range(n):
  tmp[i][i]=1
matrix=[list(map(int,input().split())) for _ in range(n)]
for i in range(60):
  if k&(1<<i):
    tmp=calc(tmp,matrix)
  matrix=calc(matrix,matrix)  
ans=0
for i in range(n):
  for j in range(n):
    ans+=tmp[i][j]
    ans%=mod
print(ans)