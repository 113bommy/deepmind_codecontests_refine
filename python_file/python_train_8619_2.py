def main():
    from bisect import bisect_left
    def update(l,r,v):
        L,R=l+N0,r+N0
        while L<R:
            if R&1:
                R-=1
                data[R-1]=v
            if L&1:
                data[L-1]=v
                L+=1
            L>>=1
            R>>=1
    def query(k):
        k+=N0-1
        s=10**18
        while k+1:
            if data[k]<s:s=data[k]
            k=~-k//2
        return s
    n,*t=open(0)
    n,q=map(int,n.split())
    d=[-10**18]+list(map(int,t[n:]))+[10**18]
    N0=2**(q+1).bit_length()
    data=[10**18]*2*N0
    for x,t,s in sorted(list(map(int,t.split()))[::-1]for t in t[:n])[::-1]:
        l=bisect_left(d,s-x)
        r=bisect_left(d,t-x)
        update(l,r,x)
    for i in range(q):
        a=query(i+1)
        print(-(a==10**18)or a)
if __name__=='__main__':
    main()