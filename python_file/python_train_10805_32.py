from collections import Counter
N = int(input())
Ass = [list(map(int, input().split())) for _ in range(N)]
ct = Counter()
q = set([(i, 0) for i in range(N)])
idxs = [0] * N
n = 0
ans = 0
while q:
  nq = set()
  for i, k in q:
    a = i+1
    b = Ass[i][k]
    if a > b: a, b = b, a
    ct[(a, b)] += 1
    if ct[(a, b)] == 2:
      n += 1
      idxs[a-1] += 1
      if idxs[a-1] < N-1:
        nq.add((a-1, idxs[a-1]))
      idxs[b-1] += 1
      if idxs[b-1] < N-1:
        nq.add((b-1, idxs[b-1]))
  ans += 1
  q = nq
if n == N * (N-1) // 2:
  print(ans)
else:
  print(-1)