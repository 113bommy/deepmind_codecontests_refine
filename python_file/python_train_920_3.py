N, x = list(map(int, input().split()))
n = N
a = list(map(int, input().split()))
b = [[1000000000000000000000 for i in range(n)] for j in range(n)]
for i in range(n):
	b[i][0] = a[i]
	for j in range(1, n):
		b[i][j] = min(b[i][j-1], a[(i-j+n)%n])
s = [0 for i in range(n)]
for i in range(n):
	for j in range(n):
		s[j] += b[i][j]
ans = 1000000000000000000000
for i in range(n):
	for j in range(n):
		ans = min(ans, j*x+s[j])
print(ans)
