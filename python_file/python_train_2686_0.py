p = int(input())
a = list(map(int,input().split()))

ans = [0]*p

for i in range(p):
    if a[i] == 0:
        continue
    ans[0] -= p-1
    m = 1
    for k in range(p):
        ans[p-1-k] -= m
        ans[p-1-k] %= p
        m *= i
        m %= p

print(*ans)
