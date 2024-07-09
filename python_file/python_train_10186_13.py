import itertools

n,m,r = map(int,input().split())
wa = [[float("INF")]*n for i in range(n)]
l = [i-1 for i in map(int,input().split())]
for i in range(m):
    a,b,c = map(int,input().split())
    a -= 1
    b -= 1
    wa[a][b] = c
    wa[b][a] = c
for i in range(n):
    wa[i][i] = 0

for k in range(n):
    for i in range(n):
        for j in range(n):
            wa[i][j] = min(wa[i][j],wa[i][k]+wa[k][j])

ans = float("INF")

for p in list(itertools.permutations(l)):
    count = 0
    for i in range(r-1):
        count += wa[p[i]][p[i+1]]
    ans = min(ans,count)
print(ans)

