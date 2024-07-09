n,k = map(int,input().split())
A = sorted(list(map(int,input().split())))
F = sorted(list(map(int,input().split())))[::-1]
o = []
for a,f in zip(A,F):
    o.append(a*f)
ok = max(o)    
ng = -1

while ok - ng > 1:
    mid = (ok+ng)//2
    k1 = 0
    for i in range(n):
        k1 += max( 0 , A[i]- mid//F[i])
    if k1<= k:
        ok = mid
    else:
        ng = mid
print(ok)
