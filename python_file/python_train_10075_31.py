n,s=map(int,input().split())
a=list(map(int,input().split()))
p=998244353

data=[[0]*(s+1) for i in range(n)]

gen=data[0]
gen[0]=2
if(a[0]<=s):
    gen[a[0]]+=1

for i in range(1,n):
    gen=data[i]
    mae=data[i-1]
    for j in range(s+1):
        gen[j]=mae[j]*2
        if(j-a[i]>=0 and j-a[i]<=s):
            gen[j]+=mae[j-a[i]]
        gen[j]%=p

print(data[-1][-1])