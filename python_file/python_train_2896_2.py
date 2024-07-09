N, K = map(int, input().split())
a = list(map(int, input().split()))
b = []
for i in range(N):
	s = 0
	for j in range(i, N):
		s = s + a[j]
		b.append(s)
max_b = len(bin(max(b))) - 2
#print(b, max_b)
ans = 0
for i in range(max_b):
	p = 0
	c = 2 ** (max_b - 1 - i)
	#print("i=",i, "c=",c)
	for j in b:
		if (ans + c) & j == ans + c:
			#print("j=",j)
			p = p + 1
	if p >= K:
		ans = ans + 2 ** (max_b - 1 - i)
		#print("ans=",ans)
print(ans)