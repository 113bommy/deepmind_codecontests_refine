n = int(input())

if n<3:
	print('No')
else:
	print('Yes')
	print(n-2, *range(2, n))
	print(2, 1, n)
