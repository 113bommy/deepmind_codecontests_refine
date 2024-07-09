from collections import deque

N = int(input())
ad = [[] for _ in range(N*N)]
num = [0] * (N*N)

for i in range(N):
    a = [int(e)-1 for e in input().split()]
    for k in range(N-2):
        j = a[k]
        nj = a[k+1]
        v = N*max(i,j) + min(i,j)
        nv = N*max(i,nj) + min(i,nj)
        ad[v].append(nv)
        num[nv] += 1

S = deque()
L = []

for v in range(N*N):
    if num[v] == 0:
        S.append((v,1))

while S:
    v, d = S.popleft()
    L.append(d)
    for nv in ad[v]:
        num[nv] -= 1
        if num[nv] == 0:
            S.append((nv, d+1))

if len(L) != N*N:
    print(-1)
    exit()

ans = max(L)
print(ans)