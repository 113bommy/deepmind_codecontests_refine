h, n = map(int, input().split())
l = [list(map(int, input().split())) for i in range(n)]
dp = [0]*20001

for i in range(1, h + 1):
    ref = 10**10
    for a, b in l:
        temp = dp[i - a] + b
        ref = min(ref, temp)
    dp[i] = ref

print(dp[h])