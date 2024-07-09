from itertools import product as p
n=int(input())
s=[[]for i in range(n+1)]
for i in range(n-1):
    a,b=map(int,input().split())
    s[a].append([b,i])
    s[b].append([a,i])
m=int(input())
l=[]
for i in range(m):
    u,v=map(int,input().split())
    a=[[]for i in range(n+1)]
    a[u]=[]
    q=[u]
    while q:
        t=q.pop(0)
        d=0
        for i,j in s[t]:
            if a[i]==[]:
                a[i]=a[t]+[j]
                q.append(i)
                if i==v:
                    d=1
                    break
        if d==1:
            break
    l.append(a[v])
for i in range(m):l[i]=set(l[i])
s=[0]*(m+1)
for i in p([0,1],repeat=m):
    d=set([])
    if sum(i)!=0:
        for j in range(m):
            if i[j]:
                d|=l[j]
        s[sum(i)]+=pow(2,n-1-len(d))
l=0
for i in range(1,m+1):
    l+=((-1)**(i-1))*s[i]
print(pow(2,n-1)-l)