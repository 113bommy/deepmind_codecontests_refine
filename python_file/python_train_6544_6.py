n=int(input())
a=list(map(int,input().split()))
a=sorted(list(enumerate(a)),key=lambda x:x[1])

l=1
while l<2*(n+2)-1:
	l*=2
l-=1
seg=[True]*l
seg[0]=False

def update(i):
	if seg[i]:
		seg[i]=False
		update((i-1)//2)

update((l-1)//2)
update((l-1)//2+n+1)

def search_left(i,j):
	if j==1:
		if i%2==1:
			return search_left((i-1)//2,1)
		else:
			if seg[i-1]:
				return search_left((i-1)//2,1)
			else:
				return search_left(i-1,0)
	else:
		if i<l//2:
			return search_left(2*i+2-seg[2*i+2],0)
		else:
			return i

def search_right(i,j):
	if j==1:
		if i%2==0:
			return search_right((i-1)//2,1)
		else:
			if seg[i+1]:
				return search_right((i-1)//2,1)
			else:
				return search_right(i+1,0)
	else:
		if i<l//2:
			return search_right(2*i+1+seg[2*i+1],0)
		else:
			return i

ans=0
for i,j in a:
	s=(l//2+1+i)
	p=search_left(s,1)
	q=search_right(s,1)
	ans+=(s-p)*(q-s)*j
	update(s)

print(ans)