def main():
	n, k = map(int, input().split())
	*a, = map(int, input().split())
	*f, = map(int, input().split())
	a.sort()
	f.sort(reverse=1)
	prod = [(y, x * y) for x, y in zip(a, f)]
	l = -1
	r = 10 ** 12
	while r - l > 1:
		m = (l + r) // 2
		s = sum(max(0, 0 - (m - p) // y) for y, p in prod)
		if s <= k:
			r = m
		else:
			l = m
	print(r)


if __name__ == "__main__":
	main()