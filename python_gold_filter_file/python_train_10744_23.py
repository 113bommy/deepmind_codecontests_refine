t = int(input())
for iiiiiiii in range(t):
	r, g, b = map(int, input().split())
	if max(r, g, b) <= r + g + b - max(r, g, b) + 1:
		print('Yes')
	else:
		print('No') 
