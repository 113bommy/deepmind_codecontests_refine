n=int(input())
from collections import Counter as co
l=co(map(int,input().split()))
ans=set()
for k in l:
    if l[k]>=2:ans.add(k)
    for j in range(2*k,10**6+1,k):
        if j in l:
            ans.add(j)
        
        
print(len(l)-len(ans))