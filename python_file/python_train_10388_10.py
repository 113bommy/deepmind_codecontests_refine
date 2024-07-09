import sys
sys.setrecursionlimit(1000000)


def input():
    return sys.stdin.readline()


n = int(input())
aa = [int(i) for i in input().split()]
e = [[] for _ in range(n)]
for _ in range(n - 1):
    a, b = [int(i) - 1 for i in input().split()]
    e[a].append(b)
    e[b].append(a)

dp = [10 ** 9] * (n + 10)
dp[0] = 0
ans1 = [0] * n
ans2 = [0] * n


def dfs(i=0, r=-1):
    global dp, ans1, ans2
    mi = 0
    ma = n
    while mi != ma:
        mm = (mi + ma) // 2
        if dp[mm] >= aa[i]:
            ma = mm
        else:
            mi = mm + 1

    be = dp[mi]
    dp[mi] = min(dp[mi], aa[i])
    ans1[i] = mi
    ans2[i] = max(ans1[i], ans2[r])

    for j in e[i]:
        if j == r:
            continue
        dfs(j, i)

    dp[mi] = be


dfs()
print("\n".join(map(str, ans2)))
