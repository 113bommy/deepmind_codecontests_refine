n, k = map(int, input().split())
v = list(map(int, input().split()))

ans = 0
for i in range(n):
    for j in range(n):
        if i + j <= k and i + j <= n:
            g = v[:i] + v[n-j:]
            g.sort()
            for l in range(1, min(k-i-j, i+j)+1):
                ans = max(ans, sum(g[l:]))

print(ans)
