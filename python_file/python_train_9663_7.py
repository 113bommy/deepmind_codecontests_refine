S = input()
MOD = 10**9 + 7
dp = [0] * 3  # num of ..A, ..AB, ..ABC
pp = [0] * 3
nq = 0
for s in S:
    pp = dp
    dp = pp.copy()
    if s == 'A':
        dp[0] += pow(3, nq, MOD)
    elif s == 'B':
        dp[1] += pp[0]
    elif s == 'C':
        dp[2] += pp[1]
    else:
        dp[0] += pp[0]*2 + pow(3, nq, MOD)
        dp[1] += pp[1]*2 + pp[0]
        dp[2] += pp[2]*2 + pp[1]
        nq += 1
    dp[0] %= MOD
    dp[1] %= MOD
    dp[2] %= MOD
print(dp[2])