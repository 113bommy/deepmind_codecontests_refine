n=int(input())
p=lambda a,b:print(a+1,b+1)
b=[0,1]
def g(n):
	print("YES")
	for i in range(n%4,n,4):
		for x in b:
			a=2*x
			for j in range(i):p(j,i+a)
			p(i+a,i+a+1)
			for j in range(i,0,-1):p(j-1,i+a+1)
		[p(i+y,i+(y^(3-x))) for y in b for x in b]
	return""
print("NO"*(n%4>1)or g(n))
