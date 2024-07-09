import queue

N, M = list(map(int, input().split()))
uv = [list(map(int, input().split())) for _ in range(M)]
S, T = list(map(int, input().split()))

V = [[0, 0, 0] for _ in range(N + 1)]
R = {}

for u, v in uv:
  if u not in R:
    R[u] = [v]
  else:
    R[u].append(v)
q = queue.Queue()
put = q.put
get = q.get

put([S, 0, 2])
ans = -1
while not q.empty():
  t = get()
  if t[0] == T and t[2] == 2:
    ans = t[1]
    break
  k = (t[2] + 1) % 3
  m = t[1]
  if t[2] == 2:
    m += 1
  if t[0] not in R: continue
  for i in R[t[0]]:
    if V[i][k] == 0:
      V[i][k] = 1
      put([i, m, k])

print(ans)