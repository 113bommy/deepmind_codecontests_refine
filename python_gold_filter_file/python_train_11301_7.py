l1,r1,l2,r2,k = [int(i) for i in input().split()]
l = max(l1,l2)
r = min(r1,r2)
if r < l :
	print(0)
elif l<=k<=r:
	print(r-l)
else:
	print(r-l+1)
