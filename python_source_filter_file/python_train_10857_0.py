n=int(input())
if n==1:
	print(4)
elif n%2==0:
	print(pow(2,n//2+1))
else:
	print(2*((n+1)//2)*((n+1)//2+1))