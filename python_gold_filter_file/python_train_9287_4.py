import math
for _ in range(int(input())):
    n,d=map(int,input().split())
    if n>=d:
        print("YES")
    else:
        k=1
        for i in range(1,n+1):
            if math.ceil((d/(i+1)))+i<=n:
                k=0
                print("YES")
                break
        if k==1:
            print("NO")