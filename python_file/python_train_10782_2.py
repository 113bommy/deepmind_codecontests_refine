def r():
	return list(map(int, input().split()))
n, ans = 0, 0
a, b, c = r()
m = int(input())
tt = []
for i in range(m):
	val, port = input().split()
	val = int(val)
	if port[0] is 'U':
		tt.append([val, 1])
	else:
		tt.append([val, 0])
tt.sort(key = lambda x: x[0])
tt2 = []
for x, y in tt:
	if y == 0 and b > 0:
		b -= 1
		ans += x
		n += 1
	elif y == 1 and a > 0:
		a -= 1
		ans += x
		n += 1
	else:
		tt2.append(x)
mn = min(c, len(tt2))
ans += sum(tt2[:mn])
n += mn
print(n, ans)