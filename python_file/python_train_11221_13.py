h,n=map(int,input().split())
ans=[10**10 for i in range(h+1)]+[0 for i in range(10**4)]
ans[0]=0
for i in range(n):
    a,b=map(int,input().split())
    tmp=0
    while tmp<=h:
        ans[tmp]=min(ans[tmp-a]+b,ans[tmp])
        tmp+=1
print(ans[h])