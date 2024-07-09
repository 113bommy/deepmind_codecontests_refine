import sys
sys.setrecursionlimit(2147483647)
INF=float("inf")
MOD=10**9+7
input=lambda :sys.stdin.readline().rstrip()
def resolve():
    n,m=map(int,input().split())
    E=[[] for _ in range(n)]
    for _ in range(m):
        s,t=map(int,input().split())
        s-=1; t-=1;
        E[s].append(t)
    dp=[0]*n
    for v in range(n-2,-1,-1):
        res=0
        for nv in E[v]: res+=dp[nv]
        dp[v]=1+res/len(E[v])
    ans=dp[0] # 辺を消さなかった時のscore

    # 各 v に対し、削除する辺 v→u は、dp[u]が最大のもの
    for v in range(n-1):
        if(len(E[v])==1): continue
        u=max(*((dp[nv],nv) for nv in E[v]))[1]
        # vu を削除したときの期待値DPを行う
        dp2=[0]*n
        for x in range(n-2,-1,-1):
            res=0
            for nx in E[x]:
                if(x==v and nx==u): continue
                res+=dp2[nx]
            if(v!=x):
                dp2[x]=1+res/len(E[x])
            else:
                dp2[x]=1+res/(len(E[x])-1)
        ans=min(ans,dp2[0])
    print(ans)
resolve()