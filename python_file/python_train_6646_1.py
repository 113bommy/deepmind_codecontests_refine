n, m = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(n)]

s = set([])
ans = n
for _ in range(m):
    memo = [0] * (m + 1)
    flag = [0] * (n + 1)
    for j in range(m):
        for i in range(n):
            if flag[i] == 0 and a[i][j] not in s:
                memo[a[i][j]] += 1
                flag[i] = 1
    idx = 0
    mmax = 0
    for i, me in enumerate(memo):
        if me > mmax:
            idx = i
            mmax = me

    ans = min(ans, mmax)
    s.add(idx)

print(ans)



