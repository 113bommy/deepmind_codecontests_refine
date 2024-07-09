n,K=map(int,input().split())
A=list(map(int,input().split()))
F=list(map(int,input().split()))
A.sort(reverse=True)
F.sort()
ng=-1
ok=10**18+1
while ok-ng>1:
             mid=(ng+ok)//2
             k=K
             for a,f in zip(A,F):
                     k-=max(0,a-mid//f)
             if k<0:
                 ng=mid
             else:
                ok=mid
print(ok)