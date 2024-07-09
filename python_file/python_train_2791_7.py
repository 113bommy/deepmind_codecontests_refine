n, k = map(int, input().split())
h_list = list(map(int, input().split()))
dp = [0]
for i in range(1, n):
    mi = min([abs(h_list[i] - h_list[j]) + dp[j] for j in range(max(0, i - k), i)])
    dp.append(mi)
print(dp[-1])