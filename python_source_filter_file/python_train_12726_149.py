t=int(input())
for i in range(t):
	n,k=list(map(int,input().split()))
	if(n==1):
		print(0)
	elif(n==2):
		print(k)
	else:
		print(2*n)
	
		
