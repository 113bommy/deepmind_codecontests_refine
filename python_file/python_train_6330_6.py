N = int(input())
a = [int(input()) for _ in range(N)]
s = sum(a)
m = (s + 1) // 2

c1 = [0] * (m + 1)
c1[m] = 1
for i in range(N):
    d = a[i]
    for j in range(m - d + 1):
        c1[j] = (2 * c1[j] + c1[j + d]) % 998244353
    for j in range(m - d + 1, m + 1):
        c1[j] = (2 * c1[j] + c1[m]) % 998244353

ans1 = c1[0]

if s % 2:
    c1[0] = 0
else:
    for j in range(m):
        c1[j] = 0
    c1[m] = 1
    for i in range(N):
        d = a[i]
        for j in range(m - d + 1):
            c1[j] = (c1[j] + c1[j + d]) % 998244353
        for j in range(m - d + 1, m + 1):
            c1[j] = c1[j]

ans = (3 ** N % 998244353 - 3 * ans1 + 3 * c1[0]) % 998244353
print(ans)