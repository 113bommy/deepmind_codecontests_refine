import sys
input = sys.stdin.readline
from collections import deque

n = int(input())
U = n**2
G = [[] for _ in range(U)]
parent = [0]*U
for i in range(n):
  A = list(map(lambda x:int(x)-1, input().split()))
  for j in range(n-2):
    a = A[j]
    b = A[j+1]
    G[min(i, a)*n+max(i, a)].append(min(i, b)*n+max(i, b))
    parent[min(i, b)*n+max(i, b)] += 1

que = deque([(i*n+j, 1) for i in range(n-1) for j in range(i+1, n) if not parent[i*n+j]])
ans = 1
cnt = 0
while que:
  v, t = que.pop()
  ans = max(ans, t)
  cnt += 1
  for nv in G[v]:
    parent[nv] -= 1
    if not parent[nv]:
      que.appendleft((nv, t+1))
if cnt == n*(n-1)//2:
  print(ans)
else:
  print(-1)