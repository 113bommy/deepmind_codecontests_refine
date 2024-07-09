#設定
import sys
input = sys.stdin.buffer.readline
sys.setrecursionlimit(10**7)

#ライブラリインポート
from collections import defaultdict
answer = 0
#入力受け取り
def getlist():
	return list(map(int, input().split()))

INF = float("inf")
class Graph(object):
	def __init__(self):
		self.graph = defaultdict(list)

	def __len__(self):
		return len(self.graph)

	def add_edge(self, a, b):
		self.graph[a].append(b)

	def get_nodes(self):
		return self.graph.keys()


def DFS(G, visit, W, Wlist, node, K):
	for i in G.graph[node]:
		if visit[i] != "Yes":
			visit[i] = "Yes"
			DFS(G, visit, W, Wlist, i, K)
			Wlist[node].append(W[i] + 1)

	val = 0
	for i in Wlist[node]:
		if i == K and node != 0:
			global answer
			answer += 1
		else:
			val = max(val, i)
	W[node] = val

#処理内容
def main():
	N, K = getlist()
	a = getlist()
	G = Graph()
	for i in range(1, N):
		G.add_edge(i, a[i] - 1)
		G.add_edge(a[i] - 1, i)
	ans = 0
	if a[0] != 1:
		ans += 1
	if K == 1:
		for i in range(1, N):
			if a[i] != 1:
				ans += 1
		print(ans)
		return

	#DFS
	W = [0] * N
	Wlist = [[] for i in range(N)]
	visit = ["No"] * N
	visit[0] = "Yes"
	
	DFS(G, visit, W, Wlist, 0, K)
	print(ans + answer)


if __name__ == '__main__':
	main()