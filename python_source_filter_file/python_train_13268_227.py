n = int(input())
sol = 0
for i in range(n):
	pi, qi = map(int, input().split())
	if qi - pi > 0:
		sol += 1
print(sol)