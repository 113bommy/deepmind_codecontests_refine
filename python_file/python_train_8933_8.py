def main():
    n,a,b,k=map(int,input().split())
    fact=[1]
    mod=998244353
    for i in range(1,n+1):fact.append(fact[-1]*i%mod)
    def inv_n(n):return pow(n,mod-2,mod)
    def nCr(n,r):return inv_n(fact[n-r]*fact[r]%mod)*fact[n]%mod
    ans=0
    ans_list=[]
    for i in range(n+1):
        j=(k-a*i)//b
        if i*a+j*b==k:
            if 0<=j<=n:
                ans_list.append([i,j])
    for p,q in ans_list:
        ans=(ans+nCr(n,p)*nCr(n,q))%mod
    print(ans)
main()