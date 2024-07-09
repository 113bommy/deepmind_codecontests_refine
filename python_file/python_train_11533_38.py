# https://atcoder.jp/contests/abc176/submissions/16164430?lang=ja
import heapq

h, w = map(int, input().split())
sh, sw = map(lambda x: int(x) - 1, input().split())
gh, gw = map(lambda x: int(x) - 1, input().split())
S = [input() for i in range(h)]

inf = 10 ** 10
D = [[inf] * w for i in range(h)]

D[sh][sw] = 0
Q = [(0, (sh, sw))]
heapq.heapify(Q)
while Q:
  _, (curr_h, curr_w) = heapq.heappop(Q)
  for di in range(-2, 3):
    for dj in range(-2, 3):
      next_h, next_w = curr_h + di, curr_w + dj
      if 0 <= next_h < h and 0 <= next_w < w and S[next_h][next_w] == ".":
        nex = int(abs(di) + abs(dj) != 1)
        if D[next_h][next_w] > D[curr_h][curr_w] + nex:
          D[next_h][next_w] = D[curr_h][curr_w] + nex
          heapq.heappush(Q, (D[next_h][next_w], (next_h, next_w)))
if D[gh][gw] >= inf:
  print(-1)
else:
  print(D[gh][gw])
