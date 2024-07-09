from math import log
n = int(input())
A = list(map(int, input().split()))
num = {}
for a in A:
	if a in num:
		num[a] += 1
	else:
		num[a] = 1

ans = 0
cnt = int(log(max(A), 2)) + 5 
for i in range(cnt, 0, -1):
	b = {}
	for x in num:
		if 2 ** i - x in b:
			b[2 ** i - x] += 1
		else:
			b[2 ** i - x] = 1
	for x in num:
		if x in b and num[x] > 0:
			if x * 2 == 2 ** i:
				ans += num[x] // 2
				num[x] %= 2
			else:
				small = min(num[x], num[2 ** i - x])
				ans += small
				num[x] -= small
				num[2 ** i - x] -= small
print(ans)
