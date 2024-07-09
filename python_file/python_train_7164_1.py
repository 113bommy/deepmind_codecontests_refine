N, M, Q = map(int,input().split())

C = [[0 for i in range(N+1)] for j in range(N+1)]
for i in range(M):
	L,R = map(int,input().split())
	C[L][R] += 1


D = [[0 for i in range(N+4)] for j in range(N+4)]
for i in range(N+1):
	for j in range(N+1):
		D[i][j+1] = D[i][j] + C[i][j]

for j in range(Q):
	p,q = map(int,input().split())
	s = 0
	for i in range(p,q+1):
		s += (D[i][q+1] - D[i][i])
	print(s)
