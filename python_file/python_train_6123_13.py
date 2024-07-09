import sys
sys.setrecursionlimit(200000)

N = int(input())
MOD = 10 ** 9 + 7

to = [[] for _ in range(N)]
for _ in range(N-1):
    x, y = map(int, input().split())
    to[x-1].append(y-1)
    to[y-1].append(x-1)

def dfs(n,p):
    w = 1
    b = 1
    for i in to[n]:
        if i != p:
            rw, rb = dfs(i, n)
            w *= (rw + rb)
            w %= MOD
            b *= rw
            b %= MOD
    return (w,b)

ans = dfs(0, -1)
print((ans[0] + ans[1]) % MOD)