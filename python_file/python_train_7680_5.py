MOD = 1000000007#い　つ　も　の
n,k = map(int,input().split())

nCk = 1#nC0
ans = 1

if k > n-1:
    k = n-1

for i in range(1,k+1,1):
    nCk = (((nCk*(n-i+1))%MOD)*pow(i,1000000005,1000000007))%MOD
    ans = (ans%MOD + ((((nCk*nCk)%MOD)*(n-i)%MOD)*pow(n,1000000005,1000000007)%MOD)%MOD)%MOD

print(ans)
