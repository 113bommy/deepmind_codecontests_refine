R,G,B,N = map(int, input().split())
cnt = 0
for r in range((N+R)//R):
	for g in range((N+G)//G):
		b = (N-(R*r+G*g))/B
		if b >= 0 and b%1==0:
			cnt += 1
print(cnt)