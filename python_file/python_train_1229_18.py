n, k, *a = map(int, open(0).read().split())
g = [0] * (k + 1)
for i in range(min(a), k + 1):
	s = set(g[i - x] for x in a if i >= x)
	r = 0
	while r in s:
		r += 1
	g[i] = r
print("First" if g[-1] else "Second")