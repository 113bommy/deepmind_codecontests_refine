import sys
mod=10**9+7 ; inf=float("inf")
from math import sqrt, ceil
from collections import deque, Counter, defaultdict #すべてのkeyが用意されてる defaultdict(int)で初期化
input=lambda: sys.stdin.readline().strip()
sys.setrecursionlimit(11451419)
from decimal import ROUND_HALF_UP,Decimal  #変換後の末尾桁を0や0.01で指定
  #Decimal((str(0.5)).quantize(Decimal('0'), rounding=ROUND_HALF_UP))
from functools import lru_cache
from bisect import bisect_left as bileft, bisect_right as biright
#メモ化再帰defの冒頭に毎回 @lru_cache(maxsize=10**10)
#引数にlistはだめ
#######ここまでテンプレ#######
#ソート、"a"+"b"、再帰ならPython3の方がいい
#######ここから天ぷら########

n,m=map(int,input().split())
G=[[] for i in range(n)]
for i in range(m):
    a,b=map(int,input().split())
    a-=1;b-=1
    G[a].append(b)
    G[b].append(a)
C=[-1]*n
C[0]=0
def dfs(x):
    for v in G[x]:
        if C[v]==C[x]:
            print(n*(n-1)//2-m)
            exit()
        if C[v]==-1:
            C[v]=1-C[x]
            dfs(v)
dfs(0)
q=C.count(0)
#print(C)
print(q*(n-q)-m)