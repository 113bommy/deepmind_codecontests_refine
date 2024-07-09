import sys
sys.setrecursionlimit(200010)

mod = 1000000007

def pow_mod(x, y):
    res = 1
    while y > 0:
        if y % 2:
            res *= x
            res %= mod
        x *= x
        x %= mod
        y //= 2
    return res


def inverse(x):
    return pow_mod(x, mod-2)

N = int(input())
E = []
for i in range(N):
    E.append([])
for i in range(N-1):
    a, b = list(map(int, input().split()))
    a -= 1
    b -= 1
    E[a].append(b)
    E[b].append(a)
kai = [1] * (N+1)
fkai = [1] * (N+1)

for i in range(N):
    kai[i+1] = kai[i] * (i+1) % mod

fkai[N] = inverse(kai[N])

for i in range(N-1, 0, -1):
    fkai[i] = fkai[i+1] * (i+1) % mod

child = [0] * N
dp = [0] * N
ans = [0] * N

def dfs1(now, par):
    res = 1
    for to in E[now]:
        if to == par:
            continue
        res += dfs1(to, now)
    child[now] = res
    return res

def dfs2(now, par):
    res = kai[child[now]-1]
    for to in E[now]:
        if to == par:
            continue
        res *= fkai[child[to]]
        res %= mod
        res *= dfs2(to, now)
        res %= mod
    dp[now] = res
    return res

def dfs3(now, par):
    ans[now] = dp[now]
    seki = 1
    for to in E[now]:
        if to == par:
            continue
        seki *= dp[to]
        seki %= mod
    for to in E[now]:
        if to == par:
            continue
        m_now = dp[now]
        m_to = dp[to]
        m_c_now = child[now]
        m_c_to = child[to]
        dp[now] *= kai[N-1-child[to]] * kai[child[to]] % mod * fkai[N-1] % mod * inverse(dp[to]) % mod
        dp[now] %= mod
        dp[to] *= kai[N-1] * dp[now] % mod * fkai[N-child[to]] % mod * fkai[child[to]-1] % mod
        dp[to] %= mod
        child[now] -= child[to]
        child[to] = N
        dfs3(to, now)
        dp[now] = m_now
        dp[to] = m_to
        child[now] = m_c_now
        child[to] = m_c_to

dfs1(0, -1)
dfs2(0, -1)
dfs3(0, -1)

for i in range(N):
    print(ans[i])
