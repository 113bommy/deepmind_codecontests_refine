#木DP, 木上の数え上げ

#前処理
#隣接リストを作る
#隣接頂点が最も多い頂点を根にして木を作る

#




def main():
    import sys
    input = sys.stdin.readline
    sys.setrecursionlimit(10000000)
    from collections import Counter, deque
    #from collections import defaultdict
    from itertools import combinations, permutations, accumulate
    #from itertools import product
    from bisect import bisect_left,bisect_right
    import heapq
    from math import floor, ceil
    #from operator import itemgetter

    #inf = 10**17
    mod = 10**9 + 7

    #頂点:0~N-1
    N = int(input())
    adj = [[] for _ in range(N)] #頂点数, 場合によって変える
    for _ in range(N-1):
        a,b = map(int, input().split())
        adj[a-1].append(b-1)
        adj[b-1].append(a-1)

    #隣接する頂点が一番多い頂点を根にする
    root = -1
    l = -1
    for i in range(N):
        t = len(adj[i])
        if t > l:
            l = t
            root = i

    #木を作る, c[i]:iの子
    c = [[] for _ in range(N)]
    #x:i, y:iの親
    def ch(x, y):
        for e in adj[x]:
            if e == y:
                continue
            c[x].append(e)
            ch(e, x)
    ch(root, -1)

    #dp[i][b, w]:iを根とする木の場合の数
    #bはiが黒, wはiが白のとき
    dp = [[-1, -1] for _ in range(N)]

    #xが葉の場合は1が返される
    #dp[x][0=b]を返す
    def black(x):
        if dp[x][0] != -1:
            return dp[x][0]
        res = 1
        for e in c[x]:
            res = white(e) * res %mod
        dp[x][0] = res
        return dp[x][0]

    #dp[x][0=w]を返す
    def white(x):
        if dp[x][1] != -1:
            return dp[x][1]
        res = 1
        for e in c[x]:
            res = ((black(e)+white(e))%mod) * res %mod
        dp[x][1] = res
        return dp[x][1]

    print((black(root)+white(root))%mod)

if __name__ == '__main__':
    main()