N=input()
L=len(N)
ans=[[0 for e in range(2)] for f in range(L)]
k=int(N[L-1])
ans[0][0]=k
ans[0][1]=10-k
if L>1:
 for i in range(1,L):
  k=int(N[L-1-i])
  ans[i][0]=min(ans[i-1][0]+k,ans[i-1][1]+k+1)
  ans[i][1]=min(ans[i-1][0]+10-k,ans[i-1][1]+10-k-1)
print(min(ans[L-1][0],ans[L-1][1]+1))
