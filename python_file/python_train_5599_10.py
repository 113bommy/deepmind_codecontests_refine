from collections import defaultdict
import sys
sys.setrecursionlimit(10**7)
INF = 10**18
t = int(input())
for _ in range(t):
    n, a, b, c, d = map(int, input().split())
    memo = defaultdict(lambda: INF)

    def dfs(n, cost):

        if memo[n] <= cost:
            return 0

        memo[n] = cost
        if n == 0:
            return 0

        dfs(0, cost+n*d)

        r = n % 2
        dfs((n-r)//2, cost+a+r*d)
        if r != 0:
            dfs((n+(2-r))//2, cost+a+(2-r)*d)

        r = n % 3
        dfs((n-r)//3, cost+b+r*d)
        if r != 0:
            dfs((n+(3-r))//3, cost+b+(3-r)*d)

        r = n % 5
        dfs((n-r)//5, cost+c+r*d)
        if r != 0:
            dfs((n+(5-r))//5, cost+c+(5-r)*d)
            
    dfs(n, 0)
    print(memo[0])
