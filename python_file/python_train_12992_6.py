from collections import defaultdict
#法と基数設定
mod1 = 10 ** 9 + 7
base1 = 1007

def getlist():
	return list(map(int, input().split()))

class UnionFind:
	def __init__(self, n):
		self.par = [i for i in range(n + 1)]
		self.rank = [0] * (n + 1)
		self.size = [1] * (n + 1)
		self.judge = "No"

	def find(self, x):
		if self.par[x] == x:
			return x
		else:
			self.par[x] = self.find(self.par[x])
			return self.par[x]

	def same_check(self, x, y):
		return self.find(x) == self.find(y)

	def union(self, x, y):
		x = self.find(x); y = self.find(y)
		if self.rank[x] < self.rank[y]:
			if self.same_check(x, y) != True:
				self.size[y] += self.size[x]
				self.size[x] = 0
			else:
				self.judge = "Yes"
			self.par[x] = y
		else:
			if self.same_check(x, y) != True:
				self.size[x] += self.size[y]
				self.size[y] = 0
			else:
				self.judge = "Yes"
			self.par[y] = x
			if self.rank[x] == self.rank[y]:
				self.rank[x] += 1

	def siz(self, x):
		x = self.find(x)
		return self.size[x]

#Nの文字からなる文字列AのM文字のハッシュ値を計算
def rollingHash(N, M, A):
	mul1 = 1
	for i in range(M):
		mul1 = (mul1 * base1) % mod1

	val1 = 0
	for i in range(M):
		val1 = val1 * base1 + A[i]
		val1 %= mod1

	hashList1 = [None] * (N - M + 1)
	hashList1[0] = val1

	for i in range(N - M):
		val1 = (val1 * base1 - A[i] * mul1 + A[i + M]) % mod1
		hashList1[i + 1] = val1

	return hashList1

#処理内容
def main():
	s = list(input())
	t = list(input())
	N = len(s)
	M = len(t)
	#sのほうを長く調整
	if N < M:
		var = int(M // N) + 1
		s = s * var
		N = N * var
	
	s = s + s
	for i in range(2 * N):
		s[i] = ord(s[i]) - 97
	for i in range(M):
		t[i] = ord(t[i]) - 97

	sHash1 = rollingHash(2 * N, M, s)
	tHash1 = rollingHash(M, M, t)
	tHash1 = tHash1[0]


	value = "No"
	UF = UnionFind(N)
	for i in range(N):
		j = (i + M) % N
		if sHash1[i] == tHash1:
			value = "Yes"
			if sHash1[j] == tHash1:
				UF.union(i, j)

	if value == "No":
		print(0)
		return

	if UF.judge == "Yes":
		print(-1)
		return

	for i in range(N):
		UF.par[i] = UF.find(i)
	ans = 0
	for i in range(N):
		ans = max(ans, UF.size[i])

	print(ans)

if __name__ == '__main__':
	main()