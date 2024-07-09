import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**9)

def solve():
    N = int(input())
    adjL = [[] for _ in range(N)]
    edges = []
    for _ in range(N-1):
        a, b = map(int, input().split())
        a, b = a-1, b-1
        adjL[a].append(b)
        adjL[b].append(a)
        edges.append((a, b))
    M = int(input())
    uvs = [tuple(map(lambda x: int(x)-1, input().split())) for _ in range(M)]

    e2Roots = [set() for _ in range(N)]
    def dfs(vNow, vPar):
        for v2 in adjL[vNow]:
            if v2 == vPar: continue
            e2Roots[v2] |= e2Roots[vNow]
            e2Roots[v2].add((vNow, v2))
            dfs(v2, vNow)

    dfs(0, -1)

    ePaths = [set() for _ in range(M)]
    for i, (u, v) in enumerate(uvs):
        ePaths[i] = e2Roots[u] ^ e2Roots[v]

    numEs = [0] * (1<<M)
    for a, b in edges:
        ptn = 0
        for iC, ePath in enumerate(ePaths):
            if (a, b) in ePath or (b, a) in ePath:
                ptn |= 1<<iC
        for S in range(1<<M):
            if S & ptn:
                numEs[S] += 1

    def getPows(base, n):
        pows = [1] * (n+1)
        for x in range(1, n+1):
            pows[x] = (pows[x-1] * base)
        return pows
    pows = getPows(2, N)

    def getNum1s(N):
        num1s = [0]
        for _ in range(N):
            num12s = [num1+1 for num1 in num1s]
            num1s += num12s
        return num1s
    num1s = getNum1s(M)

    ans = pows[N-1]
    for S in range(1, 1<<M):
        num = pows[N-1-numEs[S]]
        if num1s[S] % 2:
            ans -= num
        else:
            ans += num

    print(ans)


solve()
