import sys

def main():
	n, q = map(int, sys.stdin.readline().split())
	c = list(map(int, sys.stdin.readline().split()))
	fenwick = [0] * n
	
	def add(i, v):
		while i < n:
			fenwick[i] += v
			i = (i | (i + 1))
	
	def get(r):
		res = 0
		while r >= 0:
			res += fenwick[r]
			r = (r & (r + 1)) - 1
		return res
	
	def get_seg(l, r):
		return get(r) - get(l - 1)
		
	by_r = [[] for i in range(n)]
	for t in range(q):
		l, r = map(int, sys.stdin.readline().split())
		l, r = l - 1, r - 1
		by_r[r].append((l, t))
	last_ent = [-1] * (n + 1)
	ans = [0] * q
	for r in range(n):
		p = last_ent[c[r]]
		if p != -1:
			add(p, -1)	
		last_ent[c[r]] = r
		add(r, 1)
		for quer in by_r[r]:
			l, num = quer
			ans[num] = get_seg(l, r)
	print('\n'.join([str(x) for x in ans]))
	
main()

