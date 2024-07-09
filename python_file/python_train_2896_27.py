n , k = map(int,input().split())
a = list(map(int,input().split()))
b = []
for i in range(n):
    for j in range(i,n):
        b.append(sum(a[i:j+1]))
ans = 0
for i in reversed(range(41)):
    cou = 0
    now = ans + 2**i
    for j in b:
        if j & now >= now:
            cou += 1
    if cou >= k:
        ans += 2**i
print(ans)