import sys
def main():
    input = sys.stdin.readline
    N = int(input())
    S = [list(input().rstrip()) for _ in range(N)]

    color = [-1] * N
    color[0] = 0
    stack = [0]
    while stack:
        v = stack.pop()
        for to in range(N):
            if S[v][to] == '0': continue
            if color[to] >= 0:
                if color[to] == color[v]:
                    print(-1)
                    exit()
                continue
            stack.append(to)
            color[to] = color[v]^1

    D = [[10**9] * N for _ in range(N)]
    for i in range(N):
        for j in range(N):
            if i == j: D[i][j] = 0
            elif S[i][j] == '1': D[i][j] = 1
    for k in range(N):
        for i in range(N):
            for j in range(N):
                D[i][j] = min(D[i][j], D[i][k] + D[k][j])
    print(max(max(d) for d in D) + 1)

if __name__ == '__main__':
    main()