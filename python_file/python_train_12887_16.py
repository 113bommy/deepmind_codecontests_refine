import bisect as bs
N=int(input())
y=list(map(int, input().split()))
y.sort()
ans=0
for i in range(N-2):
  for j in range(i+1, N-1):
    tmp=y[i]+y[j]
    ans+=bs.bisect_left(y[(j+1):],tmp)
    
print(ans)

