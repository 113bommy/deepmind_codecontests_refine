N, K = map(int, input().split())
n1 = N-K
mod = 10**9+7
def comb(n, k):
    ans = 1
    for i in range(1, k+1):
        ans = ans*(n+1-i)//i
    return ans

for i in range(1, K+1):
    ans = comb(n1+1, i)
    ans %= mod
    ans *= comb(K-1, i-1)
    ans %= mod
    print(ans)
    