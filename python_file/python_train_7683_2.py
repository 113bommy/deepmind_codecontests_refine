n = int(input())
a = [[int(x) for x in input().split()] for _ in range(n)]


def bit(n, k): return (n >> k) & 1


dp = [0]*(1 << n)
flag = [False]*(1 << n)


def dfs(s):
    if flag[s] or bin(s).count("1") <= 1:
        return dp[s]
    flag[s] = True
    tmp = 0
    for i in range(n):
        for j in range(i+1, n):
            if bit(s, i) & bit(s, j):
                tmp += a[i][j]
    score = tmp
    t = (s-1) & s
    while 0 < t:
        score = max(score, dfs(t)+dfs(s ^ t))
        t = (t-1) & s
    dp[s] = score
    return dp[s]


print(dfs(2**n-1))
