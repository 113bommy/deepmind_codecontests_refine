inf=10**9+7
t=int(input())
for i in range(t):
    n,k=map(int,input().split())
    a=bin(k)[2:]
    ans=0
    for i in range(len(a)):
        if a[i]=="1":
            ans+=(n**((len(a)-i)-1))%inf
    print(ans%inf)