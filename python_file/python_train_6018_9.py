s = input()
dp = [1] + [0] * 12
for c in s:
    newdp = [0] * 13
    for d in range(10) if c == '?' else [int(c)]:
        for m in range(13):
            m2 = (m * 10 + d) % 13
            newdp[m2] = (newdp[m2] + dp[m]) % 1000000007
    dp = newdp
print(dp[5])