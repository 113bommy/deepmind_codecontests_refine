n,m = map(int,input().split())
s=[]
ans =0
for j in range(n):
	a,*b = list(map(int,input().split()))
	for i in b:
		if i<m :
			ans+=1
			s.append(j+1)
			break
s.sort()			
print(ans)
print(*s)


