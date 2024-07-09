n = int(input())
m = [[int(i) for i in input().split()] for i in range(n)]

a = 0
b = 0
c = 0
d = 0
s = 0

if n==3:
    for i in range(n):
        s += sum(m[i])
else:
    for i in range(n//3):
        a += m[len(m)//2][i]
        b += m[i][len(m)//2]
        c += m[i][i]
    for i in range(n-n//3, n):
        a += m[len(m)//2][i]
        b += m[i][len(m)//2]
        c += m[i][i]

    p = 0
    for i in range(n-1,n-n//3-1,-1):
        d += m[i][p]
        p += 1
    p = n-n//3
    for i in range(n//3-1,-1,-1):
        d += m[i][p]
        p += 1

    for h in range(n//3, n-n//3):
        for w in range(n//3, n-n//3):
            s += m[h][w]

    s += a+b+c+d
print(s)
