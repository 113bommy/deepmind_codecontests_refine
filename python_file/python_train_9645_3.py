t=int(input())
z=list(set(map(int,input().split())))
if(z[0]==0):
	print(len(z)-1)
else:
	print(len(z))
