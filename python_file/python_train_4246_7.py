import queue
n,m=map(int,input().split())
a=[[] for j in range(n)]
for i in range(0,m):
    b,c=map(int,input().split())
    a[b-1].append(c-1)
    a[c-1].append(b-1)
re=[0 for i in range(n)]
le=[0]
for i in range(0,n):
    if re[i]==0:
        ans=queue.Queue()
        ans.put(i)
        le.append(1)
        re[i]=1
        while ans.empty()==False:
            d=ans.get()
            for j in range(len(a[d])):
                if re[a[d][j]]==0:
                    ans.put(a[d][j])
                    re[a[d][j]]=1
                    le[-1]+=1
print(max(le))