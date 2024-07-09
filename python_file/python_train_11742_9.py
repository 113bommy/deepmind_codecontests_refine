import sys
sys.setrecursionlimit(10 ** 7)

def dfs(G, p, pre, t, edge, x):
    for nxt in G[p]:
        if nxt == pre:
            continue
        a, b = p, nxt
        if b < a:
            a, b = b, a
        if nxt == t:
            edge[(a, b)] += x
            return True
        if dfs(G, nxt, p, t, edge, x):
            edge[(a, b)] += x
            return True
    return False

def main():
    n = int(input())
    G = [[] for _ in range(n)]
    edge = {}
    for _ in range(n-1):
        a, b = map(int, input().split())
        a, b = a-1, b-1
        G[a].append(b)
        G[b].append(a)
        if b < a:
            a, b = b, a
        edge[(a, b)] = 0
    m = int(input())
    for i in range(m):
        u, v = map(int, input().split())
        u, v = u-1, v-1
        x = 1<<i
        dfs(G, u, -1, v, edge, x)
    ans = 2**(n-1)
    for i in range(1, 2**m):
        bit_cnt = 0
        for j in range(m):
            if (i & (1<<j)) != 0:
                bit_cnt += 1
        cnt = 0
        for v in edge.values():
            if (v & i) != 0:
                cnt += 1
        x = 2**(n-1 - cnt)
        if bit_cnt % 2 == 0:
            ans += x
        else:
            ans -= x
    print(ans)

if __name__ == "__main__":
    main()