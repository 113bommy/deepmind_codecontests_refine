n=int(input())
l=list(map(int,input().split()))
z=[]
count=0
for i in range(n-1):
	if l[i]==l[i+1]:
		count+=1
	else:
		z.append(count+1)
		count=0
z.append(count+1)
m=0
# print(z)
for i in range(len(z)-1):
	m=max(m,min(z[i],z[i+1]))	
print(2*m)		
