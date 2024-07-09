n=int(input())
for i in range(1,3501):
    for j in range(1,3501):
        t1=n*i*j
        t2=4*i*j-n*i-n*j
        if t2>0:
            k,m=divmod(t1,t2)
            if k>0 and m==0:
                print(i,j,k)
                exit()