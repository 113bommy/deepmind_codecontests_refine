import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

N,M=map(int, input().split())
B=[tuple(map(int, input().split())) for _ in range(M)]

P=list(range(N+1))
C=[1 for _ in range(N+1)]
C[0] = 0

def root(x):
    if P[x]==x: return x
    P[x] = root(P[x])
    return P[x]

def unite(a,b):
    ra = root(a)
    rb = root(b)
    C[ra] += C[rb]
    C[rb] = 0
    P[rb] = ra

def same(a,b):
    return root(a) == root(b)

def count(x):
    return C[root(x)]

ans=[0]*(M+1)
ans[M] = N * (N-1)

for i in range(M-1,-1,-1):
    a,b = B[i]
    if same(a,b):
        ans[i] = ans[i+1]
        continue
    ans[i] = ans[i+1] - count(a) * count(b)
    unite(a,b)

for i in range(1,M+1):
    print(ans[i] - ans[0])