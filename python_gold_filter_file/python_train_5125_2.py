t=int(input())
for _ in range(t):
    n,d=map(int,input().split())
    a=list(map(int,input().split()))
    i=1
    while d > 0 and i < n:
        if a[i] < d//i:
            a[0]+=a[i]
            d-=(a[i]*i)
        else:
            a[0]+=d//i
            d-=(d//i)*i
        i+=1
    print(a[0])