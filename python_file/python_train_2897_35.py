N=int(input())
A=[]
for i in range(N):
  S=input()
  A.append(S)
ans=0
for i in range(N):
  x=0
  for j in range(N):
    for k in range(N):      
      if A[j][k-i]!=A[k][j-i]:
        x=1
  if x==0:
    ans+=1
print(ans*N)