import sys

input=sys.stdin.readline
sys.setrecursionlimit(10**7)

N,M=map(int,input().split())
edge=[[] for i in range(N)]
for i in range(M):
    a,b=map(int,input().split())
    edge[a-1].append(b-1)
    edge[b-1].append(a-1)

odd=0
f=0
s=0
v=[]
for i in range(N):
    if len(edge[i])%2==1:
        odd+=1
    elif len(edge[i])==4:
        f+=1
        v.append(i)
    elif len(edge[i])>=6:
        s+=1

if odd>0:
    print("No")
else:
    if s>0:
        print("Yes")
    elif f>2:
        print("Yes")
    elif f!=2:
        print("No")
    else:
        start=v[0]
        ban=v[1]
        check=False
        def dfs(V,pv):
            global check
            if V==start and pv==-1:
                for i in edge[start]:
                    if i!=ban:
                        dfs(i,start)
            elif V==start:
                check=True
            else:
                for i in edge[V]:
                    if i!=ban and i!=pv:
                        dfs(i,V)
        dfs(start,-1)
        if check:
            print("Yes")
        else:
            print("No")
