def main():
    import sys
    input = sys.stdin.readline
    sys.setrecursionlimit(10**9)
    from collections import deque
    mod = 10**9+7
    N = int(input())
    G = [[] for _ in range(N)]
    for _ in range(N-1):
        x, y = map(int, input().split())
        G[x-1].append(y-1)
        G[y-1].append(x-1)
    que = deque([0])
    children = [[] for _ in range(N)]
    while que:
        v = que.pop()
        for nv in G[v]:
            if children[nv]:
                continue
            children[v].append(nv)
            que.append(nv)   
    memo = [[-1]*2 for _ in range(N)]
    def dp(i, c):
        if memo[i][c] >=0:
            return memo[i][c]
        if c == 1:
            res = 1
            for j in children[i]:
                res*=dp(j, 0)
                res%=mod
            memo[i][c] = res
        else:
            res = 1
            for j in children[i]:
                res*=(dp(j, 0)+dp(j, 1))
                res%=mod
            memo[i][c]= res
        return memo[i][c]
    print((dp(0, 0)+dp(0, 1))%mod)
main()
