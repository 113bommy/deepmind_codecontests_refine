from collections import deque, defaultdict
import sys
input = sys.stdin.buffer.readline
sys.setrecursionlimit(10 ** 7)

N, M = map(int, input().split())
edge = [[] for _ in range(N + 1)]
Redge = [[] for _ in range(N + 1)]
for _ in range(M):
    s, t = map(int, input().split())
    edge[s].append(t)
    Redge[t].append(s)

dp = [0.0] * (N + 1)
for s in reversed(range(1, N)):
    dp[s] = sum(dp[t] + 1.0 for t in edge[s]) / len(edge[s])
ans = dp[1]


cut = set()
for s in range(1, N):
    if len(edge[s]) > 1:
        i = edge[s][0]
        for j in edge[s]:
            if dp[i] < dp[j]:
                i = j
        cut.add((s, i))

for ng in cut:
    dp = [0.0] * (N + 1)
    for s in reversed(range(1, N)):
        E = 0.
        prob = 0.
        for t in edge[s]:
            if (s, t) == ng:
                continue
            prob += 1.0
            E += dp[t] + 1.0
        dp[s] = E / prob
    ans = min(ans, dp[1])

print(ans)