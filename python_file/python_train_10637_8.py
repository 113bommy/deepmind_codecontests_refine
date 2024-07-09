x=int(input())
v=list(map(int,input().rstrip().split()))
su=0
b=str(max(v))
l=len(b)
for i in range(x):
    count=0
    for j in range(l):
        su=((v[i]%10)*x)*(10**count+10**(count+1))+su
        count=count+2
        v[i]=v[i]//10
print(su%998244353)
    
