n = int(input())
a = [int(x) for x in input().split()]
d=[0 for i in range(10)]
for i in a:
    k=0
    while i!=0:
        d[k]+=i%10
        i=i//10
        k+=1
res=0
k=0
for i in d:
    res+=(i*n*11*(10**k))%998244353
    k+=2
print(res%998244353)
    