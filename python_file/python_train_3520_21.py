import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
sys.setrecursionlimit(10 ** 7)

N = int(input())
A = [0]+list(map(int, input().split()))

# 区間[i, j)の質量の合計はAcum[j-1] - Acum[i]
Acum = A[::]
for i in range(N):
    Acum[i + 1] += Acum[i]


cost = [[-1] * (N + 1) for _ in range(N + 1)]
for i in range(N):
    cost[i][i + 1] = 0


def slime(i, j):
    if cost[i][j] != -1:
        return cost[i][j]

    res = 10 ** 18
    mass = Acum[j] - Acum[i]
    for x in range(i + 1, j):
        res = min(res, mass + slime(i, x) + slime(x, j))
    cost[i][j] = res
    return res


ans = slime(0, N)
print(ans)
