N = int(input()) + 1
S = " "+input()
d = [[0]*N for _ in range(N)]
r = 0
for i in range(N):
    for j in range(i-1,0,-1):
        d[i][j] = d[i-1][j-1] + 1 if S[i] == S[j] else 0
        r = max(r, min(d[i][j], i-j))
print(r)
