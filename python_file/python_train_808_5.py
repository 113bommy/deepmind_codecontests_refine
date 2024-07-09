n=int(input())
A=list(map(int,input().split()))
a=0
c=0
m=max(A)
while(m):
    o=sum(map(lambda x:x&1,A))
    a+=(n-o)*o*2**c
    A=list(map(lambda x:x>>1,A))
    c+=1
    a%=10**9+7
    m//=2
print(a)