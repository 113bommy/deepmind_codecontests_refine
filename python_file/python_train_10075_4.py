n,s,*a=map(int,open(0).read().split())
mod=998244353
d=[0]*(s+1)
d[0]=1
for x in a:
	p=[0]*(s+1)
	for i in range(s+1):
		p[i]+=d[i]*2
		if i+x<=s:
			p[i+x]+=d[i]
		p[i]%=mod
	d=p
print(d[-1])