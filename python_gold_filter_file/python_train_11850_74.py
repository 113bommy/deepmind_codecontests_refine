n,m=map(int,input().split())
for i in range(m//n+1)[::-1]:
	if m%i<1:
		print(i)
		exit()