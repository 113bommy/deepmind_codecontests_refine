n = int(input())
a = sorted([x, i] for i, x in enumerate(list(map(int, input().split()))))
f = [[0 for j in range(n)] for i in range(n)]
for i in range(n-1, -1, -1):
    f[i][i] = a[0][0]*abs(a[0][1]-i)
    for j in range(i+1, n):
        f[i][j] = max(f[i+1][j]+a[j-i][0]*abs(a[j-i][1]-i), f[i][j-1]+a[j-i][0]*abs(a[j-i][1]-j))
print(f[0][n-1])