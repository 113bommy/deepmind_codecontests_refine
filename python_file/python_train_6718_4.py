a,b,c=map(int,input().split())
kitten=[0]*b
for i in range(a):
	s=input()
	for j in range(len(s)):
		if s[j] == 'Y':
			kitten[j]+=1
print(sum(map(lambda x:x>=c, kitten)))