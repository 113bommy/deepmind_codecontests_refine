import math
def combinations_count(n, r):
    return math.factorial(n) // (math.factorial(n - r) * math.factorial(r))

N,M,K = list(map(int,input().split(" ")))

ans = 0
for i in range(0,N):
    for j in range(0,M):
        mul = 2
        if i == 0 or j == 0:
            mul = 1

        ans += mul * (N -i) * (M -j) * (i+j)

ans *= combinations_count(N*M-2,K-2)
ans %= 10**9 + 7
print(ans)