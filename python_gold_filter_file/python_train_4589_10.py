while True:
	n,m = map(int, input().split())
	if n == 0 and m == 0:
		break
	cnt = 0
	
	for i in range(1, n+1):
		for j in range(i+1, n+1):
			for k in range(j+1, n+1):
				if i + j + k == m:
					cnt += 1
	print(cnt)