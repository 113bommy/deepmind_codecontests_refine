#bitDP(再帰使用)
#forの組合せでやろうとすると男性の集合/女性の集合を分けるのが難しい

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

    N = int(input())
    a = [list(map(int, input().split())) for _ in range(N)]

    #dp[s]：sは既に使った女性をbitで表していて、
    #          dp[s]は残りの男女の組合せの場合の数
    dp = [-1]*(1<<N)
    #全員相手が見つかった状態
    dp[-1] = 1

    #numは今見ている男性
    def dfs(s, num):
        #既にその状態を調べ終わっているなら返す
        if dp[s] != -1:
            return dp[s]

        #resは状態(s, num)において考えられる場合の数で
        #for文で全ての女性について考えて足している
        res = 0

        #状態sにおいて, 男性numと全ての女性とのマッチングを考える
        for i in range(N):
            #i番目の女性がまだ使っていなくて, 今見ている男性と相性が良い時
            if(s >> i) & 1 == 0 and a[num][i] == 1:
                #sを更新して, 次の男性について調べる
                #次の状態が既に調べ終わっていたらその場合の数が足される
                res += dfs(s+(1<<i), num+1)
        dp[s] = res % mod
        return dp[s]

    print(dfs(0, 0))

if __name__ == '__main__':
    main()