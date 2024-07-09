import math
import bisect
inf=10**12
a,b,q=map(int,input().split())
s=[-inf]+[int(input()) for _ in range(a)]+[inf];s.sort()
t=[-inf]+[int(input()) for _ in range(b)]+[inf];t.sort()

for i in range(q):
    x=int(input())
    p=bisect.bisect_left(s,x)
    q=bisect.bisect_left(t,x)

    sl,sr,tl,tr=s[p-1],s[p],t[q-1],t[q]

    sltl=x-min(sl,tl)
    srtr=max(sr,tr)-x
    sltr=min(x-sl*2+tr,-x-sl+tr*2)
    srtl=min(x-tl*2+sr,-x-tl+sr*2)
    print(min(sltl,srtr,sltr,srtl))