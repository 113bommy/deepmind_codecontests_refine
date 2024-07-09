
def popcount(x):
    x = x - ((x >> 1) & 0x5555555555555555)
    x = (x & 0x3333333333333333) + ((x >> 2) & 0x3333333333333333)
    x = (x + (x >> 4)) & 0x0f0f0f0f0f0f0f0f
    x = x + (x >> 8)
    x = x + (x >> 16)
    x = x + (x >> 32)
    return x & 0x0000007f


def main():
    import collections
    N = int(input())
    G = [[-1]*N for i in range(N)]

    ans = 2**(N-1)
    for i in range(N-1):
        a, b = map(int, input().split())
        a -= 1
        b -= 1
        G[a][b] = i
        G[b][a] = i
    ans = 0
    g = [[0]*N for i in range(N)]
    for i in range(N):
        q = collections.deque()
        q.append((i, 0))
        r = [True]*N
        r[i] = False
        while(q):
            x, s = q.popleft()
            for y in range(N):
                if G[x][y] >= 0 and r[y]:
                    g[i][y] = s | 1 << G[x][y]
                    q.append((y, g[i][y]))
                    r[y] = False
    M = int(input())
    s = [0 for i in range(M)]
    for i in range(M):
        u, v = map(int, input().split())
        u -= 1
        v -= 1

        s[i] = g[u][v]

    # print(s)
    for i in range(2**M):
        tmp = 2**(N-1) - 1
        c = 0
        for j in range(M):
            if (i >> j) % 2 == 1:
                tmp &= ~s[j]
                c += 1
        ans += ((-1)**(c))*(1 << popcount(tmp))

    print(ans)


main()
