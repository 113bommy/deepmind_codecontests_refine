# 解説
N=int(input())
r=N
for i in range(N+1):
  c=0;t=i
  while t>0:c+=t%6;t//=6
  t=N-i
  while t>0:c+=t%9;t//=9
  r=min(r,c)
print(r)