n,k=list(map(int,input().split()))
if k<=(n+1)/2:
    print(k*2-1)
else:
    print((k-int((n+1)/2))*2)