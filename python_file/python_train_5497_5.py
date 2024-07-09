N,K = map(int,input().split())
MOD = 10**9+7

m = 1
a,b = [],[]
while m*m <= N:
    a.append(m)
    b.append(N//m)
    m += 1
if a[-1] == b[-1]:
    b.pop()
a += b[::-1]
w = [b-a for a,b in zip([0]+a, a)]

L = len(a)
dp = [1]*L
for _ in range(K-1):
    dp2 = [0]*L
    c = 0
    for i,v in enumerate(w):
        c += dp[i] * v
        dp2[L-1-i] += c
        dp2[L-1-i] %= MOD
    dp = dp2
ans = sum(a*b for a,b in zip(w,dp))
print(ans%MOD)