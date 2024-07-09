def main():
    n,k,*a=map(int,open(0).read().split())
    a,f=sorted(a[:n])[::-1],sorted(a[n:])
    ok=10**12
    ng=-1
    while abs(ok-ng)>1:
        mid=(ok+ng)//2
        l=k
        for b,g in zip(a,f):
            if b*g>mid:
                l-=b-mid//g
        if l<0:ng=mid
        else:ok=mid
    print(ok)
main()