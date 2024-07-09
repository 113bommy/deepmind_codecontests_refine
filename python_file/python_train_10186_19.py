# readline比較用

import itertools
import sys
# input = sys.stdin.buffer.readline

N, M, R = map(int, input().split())
r = list(map(int, input().split()))

W = [[10**10 for _ in range(N+1)] for _ in range(N+1)]
for i in range(M):
  a, b, c = map(int, input().split())
  W[a][b], W[b][a] = c, c
#print(W)
  
for k in range(N+1):
  for i in range(N+1):
    for j in range(N+1):
      W[i][j] = min(W[i][j], W[i][k] + W[k][j])
#print(W)

answer = 10**10
for v in itertools.permutations(r, R):
  tmp = 0
  for i in range(1, R):
    tmp += W[v[i]][v[i-1]]
  answer = min(answer, tmp)
print(answer)