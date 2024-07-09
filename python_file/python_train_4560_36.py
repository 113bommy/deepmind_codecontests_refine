n,k = map(int,input().split())
A = list(map(int,input().split()))
F = list(map(int,input().split()))
A.sort()
F.sort(reverse=True)
l,r = 0, 10**18
if sum(A)<=k:
    print(0)
else:
    while r-l!=1:
        mid = (r+l)//2
        ex = 0
        for i in range(n):
            need = mid // F[i]
            ex += max(0, A[i]-need)
        if ex <= k:
            r = mid
        else:
            l = mid
    print(r)