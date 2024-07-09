N,C = map(int,input().split())
T = [[0 for j in range(C)] for i in range(10**5+1)]

for _ in range(N):
    s,t,c = map(int,input().split())
    T[s][c-1] += 1
    T[t][c-1] -= 1
for i in range(10**5):
    for j in range(C):
        T[i+1][j] += T[i][j]

ans = 0
for i in range(10**5):
    a = 0
    for j in range(C):
        if T[i][j] or T[i+1][j]:
            a += 1
    ans = max(ans,a)
print(ans)