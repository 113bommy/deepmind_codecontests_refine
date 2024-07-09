for i in range(int(input())):
    n,p,k=map(int,input().split())
    a=sorted(map(int,input().split()))
    max1=0
    for i in range(k):
        sum=0
        for j in range(i,n,k):
            sum+=a[j]
            if sum>p:
                break
            if j+1>max1:
                max1=j+1
    print(max1)