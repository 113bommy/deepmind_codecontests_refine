while True:
	h,w = map(int, input().split())
	if h == 0 and w == 0:
		break
	for y in range(h):
		print(''.join('#.'[(x + y) % 2] for x in range(w)))
	print('\n')