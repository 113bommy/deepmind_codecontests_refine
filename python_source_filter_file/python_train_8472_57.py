import math
n,k=map(int,input().split())
if n%2==0:
    if k>=n//2:
        print((k-n//2)*2)
    else:
        print(2*(k-1)+1)
else:
    if k<=n//2+1:
        print(2*(k-1)+1)
    else:
        print(2*(k-(n//2+1)))