mod = 998244353
N,M,K = map(int,input().split())
ans = 0
def pow(x,n):
    if n == 0:  
        return 1
    if n % 2 == 0:  
        return pow((x ** 2)%mod, n // 2)%mod
    else:
        return x * pow((x ** 2)%mod, (n - 1) // 2)%mod
A = 1
for i in range(K+1):
    p = N - i
    x = M*pow(M-1,p-1)*A % mod
    ans += x
    A = A*(N-i-1)%mod
    y = pow(i+1,mod-2)
    A = A*y % mod
print(ans%mod)