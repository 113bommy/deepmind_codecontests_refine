N, M = map(int, input().split())

if M%N == 0:
	print(M//N)
	exit()

A = []
for i in range (1, M//N+1):
	if M%i == 0:
		A.append(i)

print(A[-1])