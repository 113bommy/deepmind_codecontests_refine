a1=int(input())
a2=int(input())
k1=int(input())
k2=int(input())
n=int(input())
if(k1>k2):
	k1,k2=k2,k1
	a1,a2=a2,a1
if(n<k1*a1):
	mx=n//k1
else:
	mx=a1+(n-k1*a1)//k2
if(mx>a1+a2):
	mx=a1+a2
n-=a1*(k1-1)+a2*(k2-1)
if(n<=0):
	mi=0
else:
	mi=n
if(n>a1+a2):
	n=a1+a2
print(mi,mx)

