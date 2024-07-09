N,M = map(int,input().split())
gra = [[]for i in range(N)]
p = [[0]+[-float("inf")]*(N-1) for i in range(N*2+1)]
p[0][0] = 0
for i in range(M):
    a,b,c = map(int,input().split())
    gra[a-1].append([b-1,c])
for i in range(N*2):
    for j in range(N):
        for b,c in gra[j]:
            p[i+1][b] = max(p[i+1][b],p[i][j]+c,p[i][b])
print(["inf",p[N][-1]][p[N][-1] == p[-1][-1]])