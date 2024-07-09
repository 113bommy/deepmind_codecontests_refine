M=1000003
f=[1]
for i in range(1,M):f.append(f[i-1]*i%M)
for _ in'_'*int(input()):
	x,d,n=map(int,input().split())
	t=x*pow(d,M-2,M)%M
	print([pow(x,n,M),M-n>=t>0and f[t+n-1]*pow(f[t-1],M-2,M)*pow(d,n,M)%M or 0][d>0])