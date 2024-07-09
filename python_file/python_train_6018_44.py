mod = 10 ** 9 + 7

s = input()
dp = [0] * 13
dp[0] = 1
for i in range(len(s)):
    dp2 = [0] * 13
    for j in range(10):
        if (s[i] == '?') | (s[i] == str(j)):
            for k in range(13):
                dp2[(10 * k + j) % 13] += dp[k]
                dp2[(10 * k + j) % 13] %= mod
    dp = dp2
print(dp[5])