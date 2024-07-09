import math
q=int(input())
for _ in range(q):
    n=int(input())
    k=math.log(n,3)
    if k==int(k):
        print(n)
    else:
        if (3**(int(k)+1)-1)/2<n:
            print(int(3**(int(k)+1)))
        else:
            j=(3**(int(k)+1)-1)/2
            for i in range(int(k)-1,-1,-1):
                if j-3**i>=n:
                    j=j-3**i
            print(int(j))