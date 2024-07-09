'''input
100000 1
1 100000 100
'''
import sys
sys.setrecursionlimit(100100)
N, M = [int(x) for x in input().split()]

vien = [[] for _ in range(N)]

for _ in range(M):
	a, b, w = [int(x) for x in input().split()]
	a -= 1
	b -= 1
	w = w & 1
	vien[a].append(b)
	vien[b].append(a)

been = [False]*N
ats = 0
def dfs(x):
	been[x] = True
	for u in vien[x]:
		if not been[u]:
			dfs(u)


for i in range(N):
	if been[i]: continue

	ats += 1
	dfs(i)

print(ats)