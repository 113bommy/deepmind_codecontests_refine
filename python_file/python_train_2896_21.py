a,b = map(int,input().split())

c = list(map(int,input().split()))

aa = []
aa.append(0)
aa.append(c[0])

l = []
for i in range(1,a):
	aa.append(aa[i]+c[i])
d = 0
p = len(aa)
for i in range(p):
	for j in range(i+1,p):
		l.append(aa[j]-aa[i])
co = 0
la = 0
for i in range(40,-1,-1):
	for j in range(len(l)):
		if l[j] & (la + 2 ** i) == (la + 2 ** i):
			co += 1
	if co >= b:
		la += (2 ** i)
	co = 0

print(la)
