n, m = map(int, input().split())

dp = [float('inf') for _ in range(2 ** n)]
dp[0] = 0

for i in range(m):
    a, b = map(int, input().split())
    c = list(map(int, input().split()))
    k = 0
    p = 1
    for x in c:
        k += 2 ** (x-1)
    for j in range(2 ** n):
        L = j | k
        dp[L] = min(dp[L], dp[j] + a)

#print(dp)

if dp[-1] == float('inf'):
    print(-1)
else:
    print(dp[-1])