import bisect
n=int(input())
L=list(map(int,input().split()))
L.sort()
ans=0
for b in range(1,n-1):
    for c in range(b+1,n):
        ans+=b-bisect.bisect_right(L[:b],L[c]-L[b])
print(ans)