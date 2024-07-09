N=int(input())
S=[list(input()) for _ in range(N)]

ans=0
for k in range(N):
  ju=1
  for i in range(N):
    for j in range(N):
      if S[i][(k+j)%N]!=S[j][(k+i)%N]:
        ju=0
        
  if ju==1:
    ans+=1

print(N*ans)