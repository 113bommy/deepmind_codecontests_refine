def f (n,v,z,k):
    if n<=0: return True
    if v//z==0: return False
    return f(n-v//z,v,z*k,k)
ans,L,R=0,0,10**10
n,k=map(int,input().split())
while L<=R:
    C=(L+R)//2
    z=f(n,C,1,k)
    if z:
        ans=C
        R=C-1
    else:
        L=C+1
print(ans)
        
    
    
    
    
    
    
