n=int(input())
a=[[int(x)-1 for x in input().split()] for _ in range(n)]

cnt=0
id=[[0]*n for _ in range(n)]
for i in range(n):
	for j in range(i+1,n):
		id[i][j] = cnt
		cnt+=1
def toid(x,y):
	return id[x][y] if x<y else id[y][x]

for i in range(n):
	for j in range(n-1):
		a[i][j] = toid(i,a[i][j])

nedge = n*(n-1)//2
g=[[]for _ in range(nedge)]
to = [0]*nedge
for i in range(n):
	for j in range(1,n-1):
		g[a[i][j-1]].append(a[i][j])
		to[a[i][j]]+=1

from collections import deque

dp=[1]*nedge
q=deque([])
cnt = 0
for i in range(nedge):
	if to[i]==0:
		q.append(i)
		cnt+=1

ans = 1
while(q):
	e = q.popleft()
	for ne in g[e]:
		dp[ne] = max(dp[ne],dp[e]+1)
		to[ne]-=1
		if to[ne]==0:
			q.append(ne)
			cnt+=1
	ans = max(ans,dp[e])

if cnt != nedge:
	print(-1)
else:
	print(ans)