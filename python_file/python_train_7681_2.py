N, K = map(int, input().split())
# セグメント木(min, max)
N += 1
N0 = 2**(N-1).bit_length()
INF = float('inf')
minST = [INF]*(2*N0)
def update_min(k, x):
  k += N0-1
  minST[k] = x
  while k >= 0:
    k = (k - 1) // 2
    minST[k] = min(minST[2*k+1], minST[2*k+2])
def query_min(l, r):
  L = l + N0; R = r + N0
  s = INF
  while L < R:
    if R & 1:
      R -= 1
      s = min(s, minST[R-1])
    if L & 1:
      s = min(s, minST[L-1])
      L += 1
    L >>= 1; R >>= 1
  return s

MINF = float('-inf')
maxST = [MINF]*(2*N0)
def update_max(k, x):
  k += N0-1
  maxST[k] = x
  while k >= 0:
    k = (k - 1) // 2
    maxST[k] = max(maxST[2*k+1], maxST[2*k+2])

def query_max(l, r):
  L = l + N0; R = r + N0
  s = MINF
  while L < R:
    if R & 1:
      R -= 1
      s = max(s, maxST[R-1])
    if L & 1:
      s = max(s, maxST[L-1])
      L += 1
    L >>= 1; R >>= 1
  return s

Ps = list(map(int, input().split())) + [-1]
sorted_lens = []
tmp = 0
prev = -1
for i, p in enumerate(Ps):
  update_min(i, p)
  update_max(i, p)
  if prev > p:
    tmp = 0
  tmp += 1
  sorted_lens.append(tmp)
  prev = p

ans = N-K
flag = False
for i in range(N-K):
  smin = query_min(i, i+K+1)
  smax = query_max(i, i+K+1)
  if (smin == Ps[i] and smax == Ps[i+K]) or (flag and sorted_lens[i+K] >= K):
    ans -= 1
  if sorted_lens[i+K-1] == K:
    flag = True

print(ans)