import sys
sys.setrecursionlimit(10 ** 6)

def main():
    N = int(input())
    E = [[] for _ in range(N)]
    for i in range(N - 1):
        x, y = map(int, input().split())
        E[x - 1].append(y - 1)
        E[y - 1].append(x - 1)

    v = [False] * N
    def dp(n):
        v[n] = True
        tb = 1
        tw = 1
        for i in E[n]:
            if v[i]:
                continue
            b, w = dp(i)
            tb *= w
            tw *= w + b
        return tb, tw
    return sum(dp(0)) % (10 ** 9 + 7)


print(main())
