def main():
    import sys
    import time
    from collections import deque
    input = sys.stdin.readline
    sys.setrecursionlimit(10**6)
    N = int(input())
    P = [int(a) for a in input().strip().split()]
    G = [[min(n, N-n-1,i, N-i-1) for i in range(N)] for n in range(N)]
    Gflag = [[1] * N for _ in range(N)]
    ans = 0

    vecs = [(1, 0), (0, 1), (-1, 0), (0, -1)]

    for p in P:
        row, col = (p-1) // N, (p-1) % N
        ans += G[row][col]
        Gflag[row][col] = 0
        q = deque([(G[row][col], row, col)])
        while q:
            cost, row, col = q.popleft()
            if row > 0:
                if G[row-1][col] > cost + Gflag[row][col]:
                    G[row-1][col] = cost + Gflag[row][col]
                    q.append((cost+Gflag[row][col], row-1, col))
            if row < N-1:
                if G[row+1][col] > cost + Gflag[row][col]:
                    G[row+1][col] = cost + Gflag[row][col]
                    q.append((cost+Gflag[row][col], row+1, col))
            if col > 0:
                if G[row][col-1] > cost + Gflag[row][col]:
                    G[row][col-1] = cost + Gflag[row][col]
                    q.append((cost+Gflag[row][col], row, col-1))
            if col < N-1:
                if G[row][col+1] > cost + Gflag[row][col]:
                    G[row][col+1] = cost + Gflag[row][col]
                    q.append((cost+Gflag[row][col], row, col+1))

    print(ans)
    
if __name__ == '__main__':
    main()