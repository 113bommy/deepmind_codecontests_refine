n,c = map(int,input().split())
d = [list(map(int,input().split())) for i in range(c)]
g = [list(map(int,input().split())) for i in range(n)]
# mod=0,1,2について、色iに変えた時のコストをまとめておく
cost = [[0]*c for i in range(3)]
for i in range(3):
    for j in range(c):
        for a in range(n):
            for b in range(n):
                if (a+b)%3==i:
                    cost[i][j]+=d[g[a][b]-1][j]
# mod=0,1,2について、どの色で塗るか全探索
ret=10**10
for i in range(c):
    for j in range(c):
        for k in range(c):
            if i==j or j==k or k==i:
                continue
            ret=min(ret, cost[0][i]+cost[1][j]+cost[2][k])
print(ret)