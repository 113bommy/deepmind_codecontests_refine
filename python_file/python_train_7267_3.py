from collections import Counter

n = int(input())
a = list(map(int, input().split()))

c = Counter(a)

dp = [[[0.0 for _ in range(n+1)] for _ in range(n+1)] for _ in range(n+1)]

for z in range(c[3] + 1):
    for y in range(c[2]+1 + c[3] - z):
        for x in range(n+1 - z - y):
            if x + y + z == 0:
                continue
            ret = 0.0
            if x > 0:
                ret += dp[x-1][y][z] * x
            if y > 0:
                ret += dp[x+1][y-1][z] * y
            if z > 0:
                ret += dp[x][y+1][z-1] * z
            dp[x][y][z] = (ret + n) / (x + y + z)

print(dp[c[1]][c[2]][c[3]])
