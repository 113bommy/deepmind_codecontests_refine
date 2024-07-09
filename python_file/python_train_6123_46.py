def examA():
    N = I()
    H = LI()
    dp = [inf]*(N)
    dp[0] = 0
    for i in range(N-1):
        dp[i+1] = min(dp[i+1],dp[i]+abs(H[i+1]-H[i]))
        if i<N-2:
            dp[i + 2] = min(dp[i + 2], dp[i]+abs(H[i + 2] - H[i]))
    ans = dp[-1]
    print(ans)
    return

def examB():
    N, K = LI()
    H = LI()
    dp = [inf]*N
    dp[0] = 0
    for i in range(N):
        for k in range(1,K+1):
            if i+k>=N:
                break
            if dp[i+k]>dp[i]+abs(H[i+k]-H[i]):
                dp[i+k] = dp[i]+abs(H[i+k]-H[i])
    ans = dp[-1]
    print(ans)
    return

def examC():
    N = I()
    A = [0]*N; B = [0]*N; C = [0]*N
    for i in range(N):
        A[i],B[i],C[i] = LI()
    dp = [[0]*3 for _ in range(N+1)]
    for i in range(N):
        dp[i+1][0] = max(dp[i][1],dp[i][2]) + A[i]
        dp[i + 1][1] = max(dp[i][0], dp[i][2]) + B[i]
        dp[i + 1][2] = max(dp[i][1], dp[i][0]) + C[i]
    ans = max(dp[N])
    print(ans)
    return

def examD():
    ans = 0
    print(ans)
    return

def examE():
    ans = 0
    print(ans)
    return

def examF():
    # LCS
    S = SI(); N = len(S)
    T = SI(); M = len(T)
    dp = [[0] * (M + 1) for _ in range(N + 1)]
    for i in range(N):
        for j in range(M):
            if S[i] == T[j]:
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1)
            dp[i+1][j+1] = max(dp[i+1][j+1], dp[i+1][j], dp[i][j+1])

    i = N; j = M
    ans = []
    while i > 0 and j > 0:
        if dp[i][j] == dp[i-1][j]:
            i -= 1
        elif dp[i][j] == dp[i][j-1]:
            j -= 1
        else:
            ans.append(S[i-1])
            i -= 1
            j -= 1
    print("".join(ans[::-1]))
    return

def examG():
    # http://zehnpaard.hatenablog.com/entry/2018/06/26/201512
    # トポロジカルソート
    def topological_sort(n,outs,ins):
        q = deque(v1 for v1 in range(n) if ins[v1] == 0)
        res = []
        while q:
            v1 = q.popleft()
            res.append(v1)
            for v2 in outs[v1]:
                ins[v2] -= 1
                if ins[v2] == 0:
                    q.append(v2)
        return res
    N, M = LI()
    V = [[]for _ in range(N)]
    start = [0]*N
    for _ in range(M):
        x,y = LI()
        x -= 1; y -= 1
        V[x].append(y)
        start[y] += 1
    Order = topological_sort(N, V, start)
#    print(Order)
    dp = [0]*N
    for i in Order:
        for v in V[i]:
            dp[v] = max(dp[v],dp[i]+1)
    ans = max(dp)
    print(ans)
    return

def examH():
    H, W = LI()
    A = [SI() for _ in range(H)]
    dp = [[0]*W for _ in range(H)]
    dp[0][0] = 1
    for i in range(H):
        for j in range(W):
            if A[i][j]=="#":
                continue
            dp[i][j] %=mod
            if i+1<H and dp[i+1][j]!="#":
                dp[i+1][j] +=dp[i][j]
            if j+1<W and dp[i][j+1]!="#":
                dp[i][j+1] +=dp[i][j]
    ans = dp[-1][-1]
    print(ans)
    return

def examI():
    N = I()
    P = LFI()
    dp = [[0]*(N+1) for _ in range(N+1)]
    dp[0][0] = 1
    for i in range(N):
        for j in range(i+1):
            dp[i+1][j+1] += dp[i][j]*P[i]
            dp[i+1][j] += dp[i][j]*(1-P[i])
    ans = 0
    for v in dp[N][(1+N//2):]:
        ans += v
    print(ans)
    return

def examJ():
    N = I()
    A = LI()
    dp = [[[0]*(N+1) for _ in range(N+1)]for _ in range(N+1)]
    S = Counter(A)
    print(S)
    dp[S[1]][S[2]][S[3]] = 0
    que = deque()
    que.append((S[1],S[2],S[3]))
    used = defaultdict(set)
    while(que):
        n1,n2,n3 = que.popleft()
        if used[(n1,n2,n3)]:
            continue
        used[(n1,n2,n3)] = True
        now = n1+n2+n3
        if n1>0:
            dp[n1-1][n2][n3] += dp[n1][n2][n3] + N/now * n1/now
            que.append((n1-1, n2, n3))
        if n2>0:
            dp[n1+1][n2-1][n3] += dp[n1][n2][n3] + N/now * n2/now
            que.append((n1+1,n2-1,n3))
        if n3>0:
            dp[n1][n2+1][n3-1] += dp[n1][n2][n3] + N/now * n3/now
            que.append((n1,n2+1,n3-1))
#    print(dp)
    ans = dp[0][0][0]
    print(ans)
    return

def examK():
    N, K = LI()
    A = LI()
    dp = [-1]*(K+1)
    for i in range(1,K+1):
        flag = False
        for a in A:
            if a>i:
                break
            if dp[i-a]==-1:
                flag = True
                break
        if flag:
            dp[i] = 1
#    print(dp)
    ans = dp[K]
    if ans==1:
        print("First")
    else:
        print("Second")
    return

def examM():
    N, K = LI()
    A = LI()
    dp = [[0]*(K+1) for _ in range(N+1)]
    dp[0][0] = 1
    for i in range(N):
        cum = [0]*(K+1)
        cum[0] = dp[i][0]
        for c in range(K):
            cum[c+1] = cum[c] + dp[i][c+1]
        for j in range(K+1):
            if j<=A[i]:
                dp[i+1][j] = cum[j]
            else:
                dp[i+1][j] = cum[j] - cum[j-A[i]-1]
            dp[i+1][j] %=mod
#    print(dp)
    ans = dp[N][K]%mod
    print(ans)
    return

def examP():
    def dfs_dp(n,s,fords,visited):
        W = 1; B = 1
        visited[s] = True
        for v in fords[s]:
            if visited[v]:
                continue
            cur = dfs_dp(n, v, fords,visited)
            W *= sum(cur)
            B *= cur[0]
            W %= mod
            B %= mod
#        print(s,W,B)
        return (W,B)
    N = I()
    V = [[]for _ in range(N)]
    for _ in range(N-1):
        x,y = LI()
        x -=1; y -=1
        V[x].append(y)
        V[y].append(x)
    visited = [False]*N
    ans = dfs_dp(N,0,V,visited)
    print(sum(ans)%mod)
    return

import sys,copy,bisect,itertools,heapq,math
from heapq import heappop,heappush,heapify
from collections import Counter,defaultdict,deque
def I(): return int(sys.stdin.readline())
def LI(): return list(map(int,sys.stdin.readline().split()))
def LFI(): return list(map(float,sys.stdin.readline().split()))
def LSI(): return list(map(str,sys.stdin.readline().split()))
def LS(): return sys.stdin.readline().split()
def SI(): return sys.stdin.readline().strip()
global mod,mod2,inf,alphabet
mod = 10**9 + 7
mod2 = 998244353
inf = 10**18
alphabet = [chr(ord('a') + i) for i in range(26)]

sys.setrecursionlimit(10**6)

if __name__ == '__main__':
    examP()

"""

"""