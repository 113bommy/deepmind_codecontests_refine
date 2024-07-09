
import sys
sys.setrecursionlimit(10 ** 7)
inp = sys.stdin.buffer.readline


def resolve():
    MOD = 10 ** 9 + 7

    # 0: white, 1: black
    def dfs(v, parent):
        vistied[v] = True
        dp[v][0] = 1
        dp[v][1] = 1
        for to in G[v]:
            if to == parent or vistied[to]:
                continue
            dfs(to, v)
            # 親が白の時は子は白黒どっちでも良い
            # 親が黒の時は子は白のみ
            dp[v][0] *= (dp[to][0] + dp[to][1]) % MOD
            dp[v][1] *= dp[to][0] % MOD

    N = int(inp())
    G = [[] for _ in range(N)]
    for _ in range(N - 1):
        x, y = map(lambda x: int(x) - 1, inp().split())
        G[x].append(y)
        G[y].append(x)
    dp = [[0] * 2 for _ in range(N)]
    vistied = [False] * N

    dfs(0, -1)
    ans = dp[0][0] + dp[0][1]
    print(ans % MOD)


if __name__ == "__main__":
    resolve()