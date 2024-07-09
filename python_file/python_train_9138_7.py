N=int(input())
S=[input() for i in range(N)]
G=[[] for i in range(N)]
for i in range(N):
    for j in range(N):
        if S[i][j]=="1":
            G[i].append(j)
q=[0]
dist=[-1 for i in range(N)]
dist[0]=0
while(q):
    r=q.pop()
    for p in G[r]:
        if dist[p]==-1:
            dist[p]=1-dist[r]
            q.append(p)
for i in range(N):
    for j in G[i]:
        if dist[i]==dist[j]:
            print(-1)
            exit()
#possible
#print(G)
d=[[10**9 for i in range(N)] for i in range(N)]
for i in range(N):
    for j in G[i]:
        d[i][j]=1
    d[i][i]=0

for k in range(N):
    for i in range(N):
        for j in range(N):
            if d[i][j]>d[i][k]+d[k][j]:
                d[i][j]=d[i][k]+d[k][j]
ans=2
for i in range(N):
    for j in range(N):
        ans=max(ans,d[i][j]+1)
print(ans)
