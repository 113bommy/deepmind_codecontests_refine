n=int(input())
a=list(map(int,input().split()))
if n==1:
    print(-1)
elif n==2:
    if a[0]==a[1]:
        print(-1)
    else:
        print(1)
        print(a.index(min(a)))
else:
    print(1)
    print(a.index(min(a)) + 1)
