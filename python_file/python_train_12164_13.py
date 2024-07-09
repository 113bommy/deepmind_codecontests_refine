def main():
	n = int(input())
	*t, = map(int, input().split())
	tot = sum(t)
	*v, = map(int, input().split())
	lim1 = []
	lim2 = [(1, 0, 0), (-1, tot, tot)]
	til = 0
	for t1, t2, v1 in zip([0] + t, t, v):
		lim1.append((til, til + t2, v1))
		lim2.append((-1, til, til + v1))
		lim2.append((1, til + t2, v1 - (til + t2)))
		til += t2

	def mi(time):
		ret = float("inf")
		for l, r, lim in lim1:
			if l <= time <= r:
				ret = min(ret, lim)
		for f, tt, y in lim2:
			if f == -1 and time <= tt:
				ret = min(ret, y - time)
			if f == 1 and time >= tt:
				ret = min(ret, time + y)
		return ret

	print(sum(mi(i / 2) for i in range(tot * 2 + 1)) / 2)

if __name__ == '__main__':
	main()