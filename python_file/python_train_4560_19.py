n,k=map(int,input().split())
a=list(map(int,input().split()))
f=list(map(int,input().split()))
a.sort()
f.sort(reverse=True)
hi=10**12
lo=0
def c(mi):
    tmp=0
    for i,j in zip(a,f):
        if mi//j<i:
            tmp+=i-mi//j
    if tmp<=k:
        return True
    return False
while hi>=lo:
    mi=(hi+lo)//2
    if c(mi):
        hi=mi-1
    else:
        lo=mi+1
print(lo)