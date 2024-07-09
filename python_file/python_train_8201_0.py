n = int(input())
a = list(map(int, input().split()))

ans = 0
#even = []
for i in range(60):
	cnt = 0
	for x in a:
		if (x>>i) & 1:
			cnt += 1
	if cnt%2 == 1:
		ans += (1<<i)
		for j in range(n):
			if (a[j]>>i) & 1:
				a[j] -= (1<<i)
#print(ans, even)

yet = 0
for r in range(59, -1, -1):
	stood = False
	for c in range(yet, n):
		if (a[c]>>r) & 1:
			if not stood:
				stood = True
				a[yet], a[c] = a[c], a[yet]
				yet += 1
	if stood:
		for c in range(n):
			if c == yet-1 or (a[c]>>r) & 1 == 0:
				continue
			#print(c)
			a[c] ^= a[yet-1]

tmp = 0
res = 0
for c in range(n):
	tmp ^= a[c]
	res = max(res, tmp) 

print(ans + (res<<1))