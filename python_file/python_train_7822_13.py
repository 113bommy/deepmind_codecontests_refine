n=int(input())
a=list(map(int,input().split()))

i=0
j=n-1
s=''
p=min(a[0],a[-1])-1
# print(p)
while i<j:
	# pr	int(a[i],a[j],p)
	if a[i]>a[j] and a[j]>p:
		p=a[j]
		j-=1
		s+='R'
	elif a[i]>a[j] and a[i]>p:
		p=a[i]
		i+=1
		s+='L'
	elif a[i]<a[j] and a[i]>p:
		p=a[i]
		i+=1
		s+='L'
	elif a[i]<a[j] and a[j]>p:
		p=a[j]
		j-=1
		s+='R'
	else:
		break
if a[i]>p:
	s+='R'
print(len(s))
print(s)
