from collections import defaultdict
import sys

sys.setrecursionlimit(10 ** 6)
int1 = lambda x: int(x) - 1
p2D = lambda x: print(*x, sep="\n")
def II(): return int(sys.stdin.readline())
def MI(): return map(int, sys.stdin.readline().split())
def MI1(): return map(int1, sys.stdin.readline().split())
def LI(): return list(map(int, sys.stdin.readline().split()))
def LLI(rows_number): return [LI() for _ in range(rows_number)]
def SI(): return sys.stdin.readline()[:-1]

def main():
    def dfs(u, v, pu=-1):
        if u == v: return True
        for cu in to[u]:
            if cu == pu: continue
            if dfs(cu, v, u):
                path.append(uvtoi[u, cu])
                return True
        return False

    to = defaultdict(list)
    n = II()
    uvtoi = {}
    for i in range(n - 1):
        a, b = MI1()
        to[a].append(b)
        to[b].append(a)
        uvtoi[a, b] = i
        uvtoi[b, a] = i
    m = II()
    itoj = defaultdict(list)
    for j in range(m):
        u, v = MI1()
        path = []
        dfs(u, v)
        #print(path)
        for i in path: itoj[i].append(j)
    #print(itoj)
    en = len(itoj)
    dp = [[0] * (1 << m) for _ in range(en + 1)]
    dp[0][0] = 1
    for i, jj in enumerate(itoj.values()):
        mask = sum(1 << j for j in jj)
        for bit in range(1 << m):
            pre = dp[i][bit]
            if pre == 0: continue
            dp[i + 1][bit | mask] += pre
            dp[i + 1][bit] += pre
    #print(dp)
    ans=dp[-1][-1]*pow(2,n-1-en)
    print(ans)

main()
