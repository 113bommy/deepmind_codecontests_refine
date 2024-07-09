from _collections import deque

n,m=map(int,input().split())
f=[[] for i in range(n+1)]
for i in range(m):
    a,b=map(int,input().split())
    f[a].append(b)
    f[b].append(a)
g=[0]*(n+1)
p=[0]*(n+1)
for i in range(1,n+1):
    if p[i]==0:
        p[i]=i
        data=[i]
        data=deque(data)
        while len(data)>0:
            pos=data.popleft()
            p[pos]=i
            for j in f[pos]:
                if p[j]==0:
                    data.append(j)
for i in range(n):
    g[p[i+1]]+=1
print(max(g))
