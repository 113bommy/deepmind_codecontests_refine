n,m=map(int,input().split())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
import bisect
mod=10**9+7
a.sort()
b.sort()
ans=1
flag=True
if len(set(a))!=n or len(set(b))!=m:
    flag=False
    print(0)
def find(X,lists):
    return bisect.bisect_right(lists,X)!=bisect.bisect_left(lists,X)
    
if flag:
    for i in range(n*m,0,-1):
        #n*m-i+1番目の値をたす.
        if find(i,a):
            if find(i,b):
                pass    
            else:
                ans*=(m-bisect.bisect_left(b,i))
                ans=ans%mod
            
        else:
            if find(i,b):
                ans*=(n-bisect.bisect_right(a,i))
                ans=ans%mod
                
            else:
                ans*=((n-bisect.bisect_left(a,i))*(m-bisect.bisect_left(b,i))-(n*m-i))
                ans=ans%mod
    print(ans)             

