import sys


sys.setrecursionlimit(10 ** 6)
INF = float("inf")
MOD = 10 ** 9 + 7


def input():
    return sys.stdin.readline().strip()


def bellman_ford(edges, n_nodes, start, goal):
    dist = [float("inf") for _ in range(n_nodes)]
    dist[start] = 0

    for i in range(2 * n_nodes):
        for fro, to, cost in edges:
            if dist[to] > dist[fro] + cost:
                dist[to] = dist[fro] + cost
                if i == n_nodes - 1:
                    dist[to] = -float("inf")

    return -dist[goal]


def main():
    N, M, P = map(int, input().split())
    edges = []
    for _ in range(M):
        a, b, c = map(int, input().split())
        edges.append((a - 1, b - 1, -c + P))

    ans = bellman_ford(edges, N, 0, N - 1)
    if ans == float("inf"):
        print(-1)
    else:
        print(max(ans, 0))


if __name__ == "__main__":
    main()
