import sys
input = sys.stdin.readline

n, k = [int(item) for item in input().split()]
a = [int(item) for item in input().split()]
a.sort(reverse=True)
# 1-indexed
cumsum = [0] * (n + 1)
for i in range(n):
    cumsum[i+1] = cumsum[i] + a[i]
coef = [0] * (n + 1)
for i in range(n + 1):
    coef[i] = (2 + i) ** 2 - (1 + i) ** 2
coef[0] += 2

ans = 10**18
for trip in range(1, n+1):
    collected = 0
    to_take = (n + trip - 1) // trip
    score = k * trip + k * n
    for i in range(to_take):
        val = cumsum[min((i+1) * trip, n)] - cumsum[i * trip]
        score += val * coef[i]
    ans = min(ans, score)
print(ans)