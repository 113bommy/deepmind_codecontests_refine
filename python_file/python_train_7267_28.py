import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**7)

N = int(input())
a = list(map(int, input().split()))

one = a.count(1)
two = a.count(2)
three = a.count(3)

dp = [[[0.0] * (N + 1) for _ in range((N + 1))] for _ in range((N + 1))]

max_one = one + two + three
max_two = two + three
max_three = three

for k in range(max_three + 1):
    for j in range(max_two + 1 - k):
        for i in range(max_one + 1 - j - k):
            if i + j + k == 0:
                continue
            else:
                r = N

            if i > 0:
                r += dp[i - 1][j][k] * i
            if j > 0:
                r += dp[i + 1][j - 1][k] * j
            if k > 0:
                r += dp[i][j + 1][k - 1] * k

            dp[i][j][k] = r / (i + j + k)

print(dp[one][two][three])
