import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline


n = int(input())
info = [list(map(int, input().split())) for i in range(n-1)]
MOD = 10**9 + 7

tree = [[] for i in range(n)]
for i in range(n-1):
    x, y = info[i]
    x -= 1
    y -= 1
    tree[x].append(y)
    tree[y].append(x)

def solve(pos):
    b = 1
    w = 1
    flag = False
    for next_pos in tree[pos]:
        if not visited[next_pos]:
            visited[next_pos] = True
            flag = True
            tmp_b, tmp_w = solve(next_pos)
            w *= (tmp_b + tmp_w)
            b *= tmp_w
            w %= MOD
            b %= MOD
    if not flag:
        black[pos] = 1
        white[pos] = 1
        return (black[pos], white[pos])
    else:
        black[pos] = b
        white[pos] = w
        return (black[pos], white[pos])

black = [0]*n
white = [0]*n
visited = [False]*n
visited[0] = True
print(sum(solve(0)) % MOD)