import heapq
# numeric_limitsわかんね
NUMERIC_LIMITS = 10 ** 18

class mcf_graph:
  pos = []
  def __init__ (s, n):
    s._n = n
    s.g = [[] for _ in range(n)]

  def add_edge(s, frm, to, cap, cost):
    m = len(s.pos)
    s.pos.append([frm, len(s.g[frm])])
    s.g[frm].append(s._edge(to, len(s.g[to]), cap, cost))
    s.g[to].append(s._edge(frm, len(s.g[frm]) - 1, 0, -cost))
    return m

  class edge:
    def __init__(s, frm, to, cap, flow, cost):
      s.frm, s.to = frm, to
      s.cap, s.flow, s.cost = cap, flow, cost

  def get_edge(s, i):
    m = len(s.pos)
    _e = s.g[s.pos[i][0]][s.pos[i][1]]
    _re = s.g[_e.to][_e.rev]
    return s.edge(s.pos[i][0], _e.to, _e.cap + _re.cap, _re.cap, _e.cost)

  def edges(s):
    return [s.get_edge(i) for i in range(len(s.pos))]

  def flow(self, s, t, flow_limit = NUMERIC_LIMITS):
    return self.slope(s, t, flow_limit)[-1]

  def slope(self, s, t, flow_limit = NUMERIC_LIMITS):
    #priority_queueの代わり
    push = heapq.heappush
    pop = heapq.heappop
    dual, dist = [0] * self._n, [0] * self._n
    pv, pe = [0] * self._n, [0] * self._n
    vis = [False] * self._n

    def dual_ref():
      for i in range(self._n):
        dist[i] = NUMERIC_LIMITS
        pv[i] = -1
        pe[i] = -1
        vis[i] = False
      class Q:
        def __init__(s, key, to):
          s.key = key
          s.to = to
        def __lt__(s, r):
          return s.key < r.key
      que = []
      dist[s] = 0
      push(que, Q(0, s))
      while len(que):
        v = pop(que).to
        if vis[v]: continue
        vis[v] = True
        if v == t: break
        for i in range(len(self.g[v])):
          e = self.g[v][i]
          if vis[e.to] or not e.cap: continue
          cost = e.cost - dual[e.to] + dual[v]
          if dist[e.to] - dist[v] > cost:
            dist[e.to] = dist[v] + cost
            pv[e.to] = v
            pe[e.to] = i
            push(que, Q(dist[e.to], e.to))
      if not vis[t]: return False
      for v in range(self._n):
        if not vis[v]: continue
        dual[v] -= dist[t] - dist[v]
      return True
    
    flow = 0
    cost, prev_cost = 0, -1
    result = []
    result.append([flow, cost])
    while flow < flow_limit:
      if not dual_ref(): break
      c = flow_limit - flow
      v = t
      while v != s:
        c = min(c, self.g[pv[v]][pe[v]].cap)
        v = pv[v]
      v = t
      while v != s:
        e = self.g[pv[v]][pe[v]]
        e.cap -= c
        self.g[v][e.rev].cap += c
        v = pv[v]
      d = -dual[s]
      flow += c
      cost += c * d
      if prev_cost == d:
        result.pop()
      result.append([flow, cost])
      prev_cost = cost
    return result

  class _edge:
    def __init__(s, to, rev, cap, cost):
      s.to, s.rev = to, rev
      s.cap, s.cost = cap, cost

#-------最強ライブラリここまで------

def main():
  N, K = list(map(int, input().split()))
  A = [list(map(int, input().split())) for _ in range(N)] 
  BIG = 10 ** 9

  g = mcf_graph(2 * N + 2)
  s = 2 * N
  t = 2 * N + 1

  g.add_edge(s, t, N * K, BIG)

  #   k,0|1,A[i][j]|k,0
  #      列0 ー 行0
  #   ／　　 ×     ＼
  # s ー 列1 米 行1 ー t
  #   ＼  　 ×     ／
  #      列i ー 行j
  for i in range(N):
    g.add_edge(s, i, K, 0)
    g.add_edge(N + i, t, K, 0)
  for i in range(N):
    for j in range(N):
      g.add_edge(i, N + j, 1, BIG - A[i][j])

  result = g.flow(s, t, N * K)
  print(N * K * BIG - result[1])

  grid = [["."] * N for _ in range(N)]
  edges = g.edges()
  for e in edges:
    if e.frm == s or e.to == t or e.flow == 0: continue
    grid[e.frm][e.to - N] = "X"

  for g in grid:
    print("".join(g))

main()
