N=int(input())
for h in range(1,3501):
	for n in range(1,3501):
		tmp=4*h*n-N*n-N*h
		if tmp==0:continue
		w=N*n*h/tmp
		if 1<=w<=3500 and w==int(w):
			print(h,n,int(w))
			exit()
		