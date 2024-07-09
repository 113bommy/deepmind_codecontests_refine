#!/usr/bin/env python3
import sys
import heapq
INF = float("inf")


def argmax(a):
    m, n = -(1 << 31), -1
    for i, v in enumerate(a):
        if m < v:
            m, n = v, i
    return m, n

# 無向グラフを仮定する。


class Graph(object):
    def __init__(self, N):
        self.N = N
        self.V = list(range(N))
        self.E = [[] for _ in range(N)]

    def add_edge(self, edge):
        """辺を加える。edgeは(始点, 終点、重み)からなるリスト
        重みがなければ、重み1とする。
        """
        if len(edge) == 2:
            edge.append(1)
        elif len(edge) != 3:
            print("error in add_edge")
            pass

        s, t, w = edge
        self.E[s].append([t, w])
        self.E[t].append([s, w])  # 無向グラフを仮定。逆向きにも辺を張る

        pass


def shortestPath(g: Graph, s: int):
    """ グラフgにおいて、始点sから各頂点への最短路を求める
    引数
    g: グラフ, s: 始点
    返り値
    dist: 始点からの距離が格納されたリスト
    prev: 始点から最短経路で移動する場合、各頂点に至る前の頂点のリスト
    """
    dist = [INF]*g.N
    dist[s] = 0

    prev = [None]*g.N
    Q = []
    heapq.heappush(Q, (dist[s], s))

    while len(Q) > 0:
        _, u = heapq.heappop(Q)
        for v, w in g.E[u]:
            if dist[v] > dist[u] + w:
                dist[v] = dist[u] + w
                prev[v] = u
                heapq.heappush(Q, (dist[v], v))
    return dist, prev


def tree_diameter(g):
    # 木の直径を求める。
    # ダイクストラ法を二回行う実装。
    dist, prev = shortestPath(g, 0)
    m, s = argmax(dist)
    dist, prev = shortestPath(g, s)
    return max(dist)


def solve(N: int, a: "List[int]", b: "List[int]"):
    g = Graph(N)
    for aa, bb in zip(a, b):
        g.add_edge([aa-1, bb-1])

    L = tree_diameter(g)
    if L % 3 == 1:
        print("Second")
    else:
        print("First")
    return


def main():

    def iterate_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word
    tokens = iterate_tokens()
    N = int(next(tokens))  # type: int
    a = [int()] * (N-1)  # type: "List[int]"
    b = [int()] * (N-1)  # type: "List[int]"
    for i in range(N-1):
        a[i] = int(next(tokens))
        b[i] = int(next(tokens))
    solve(N, a, b)


if __name__ == '__main__':
    main()
