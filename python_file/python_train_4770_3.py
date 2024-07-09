import sys
sys.setrecursionlimit(4100000)

def os(): return input()
def oi(): return int(input())
def oli(): return map(int, input().split())
def olai(): return list(map(int, input().split()))
def olas(): return list(input().split())
def mlai(L): return [int(input()) for _ in range(L)]
def mlas(L): return [input() for _ in range(L)]
def ar(a, b, c=-1, d=-1, INIT=0):
    if(c==-1): return [[INIT]*b for _ in range(a)]
    if(d==-1): return [[[INIT]*c for _ in range(b)] for __ in range(a)]
    return [[[[INIT]*d for _ in range(c)] for __ in range(b)] for ___ in range(a)]

n, m = oli()

#全方位木dp
#-------------------------------------------------------------------
#扱うクラス


#零元
zero = 1

#一個上に遷移した時の変化
def step(x):
    return x+1
#マージ
def merge(x, y):
    return (x*y)%m

G = [[] for _ in range(100001)]
down_data = [zero for _ in range(100001)]
dat = [zero for _ in range(100001)]

def dfs(now, parent):
    cnt = 0
    for to in G[now]:
        if(to==parent): continue
        cnt += 1
        dfs(to, now)
        down_data[now] = merge(down_data[now], step(down_data[to]))

def dfs_rev(now, parent, rev):
    #累積
    left = []
    right = []
    cnt = 0
    for to in G[now]:
        if(to==parent): continue
        if(len(left)==0): left.append(step(down_data[to]))
        else: left.append(merge(left[cnt-1], step(down_data[to])))
        cnt += 1
    cnt = 0
    for to in reversed(G[now]):
        if(to==parent): continue
        if(len(right)==0): right.append(step(down_data[to]))
        else: right.append(merge(right[cnt-1], step(down_data[to])))
        cnt += 1
    cnt = 0
    dat[now] = merge(rev, down_data[now])

    for to in G[now]:
        if(to==parent): continue
        x = zero if cnt==0 else left[cnt-1]
        y = zero if cnt==len(right)-1 else right[len(right)-2-cnt]
        dfs_rev(to, now, step(merge(rev, merge(x, y))))
        cnt += 1

def calc(N):
    root = -1
    for i in range(1, N+1):
        if(len(G[i]) == 1 or len(G[i]) == 0):
            root = i
            break
    dfs(root, -1)
    dfs_rev(root, -1, zero)
#-------------------------------------------------------------------

for i in range(n-1):
    a, b = oli()
    G[a].append(b)
    G[b].append(a)
calc(n)
for i in range(1, n+1):
    print(dat[i])
