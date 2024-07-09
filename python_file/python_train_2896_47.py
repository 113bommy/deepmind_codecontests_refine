n, k = map(int, input().split())
a = list(map(int, input().split()))

# 部分和の作成
l = []
for i in range(n):
    t=0
    for j in range(i, n):
        t += a[j]
        l.append(t)
ans = 0
for i in range(40, -1, -1):
    x = 2 ** i
    s = []
    for ll in l:
        if (ans + x) & ll == (ans + x):
            s.append(ll)
    if len(s) >= k:
        ans += x
print(ans)

