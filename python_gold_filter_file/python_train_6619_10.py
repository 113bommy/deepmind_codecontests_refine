n = int(input())
a = [int(i) for i in input().split()]

k, x, l = 0, 0, set()
for i in range(2*n):
	if a[i] not in l:
		k += 1
		l.add(a[i])
	else:
		x = max(k, x)
		k -= 1
	
print(x)