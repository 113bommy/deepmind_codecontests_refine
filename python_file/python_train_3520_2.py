

def rec(a, s, e, dp, ss):
    if dp[s][e] > 0:
        return dp[s][e]

    if e - s == 1:
        dp[s][e] = 0
        return 0
    
    cur_min = float('inf')
    for i in range(s + 1, e):
        lc = rec(a, s, i, dp, ss)
        rc = rec(a, i, e, dp, ss)
        test = lc + rc + ss[s][e]
        if test < cur_min:
            cur_min = test
    dp[s][e] = cur_min
    return cur_min


def submit():
    n = int(input())
    a = list(map(int, input().split()))
    dp = [[0 for _ in range(n + 1)] for _ in range(n + 1)]
    ss = [[0 for _ in range(n + 1)] for _ in range(n + 1)]

    for i in range(n + 1):
        for j in range(i, n + 1):
            ss[i][j] = sum(a[i:j])
    
    print(rec(a, 0, n, dp, ss))


submit()