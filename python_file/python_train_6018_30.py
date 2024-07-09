s = input()
MOD = 10**9+7
old_dp=[0]*13
new_dp=[0]*13
old_dp[0]=1

for c in s:
    for i in range(13):
        if c == '?':
            for d in range(10):
                new_dp[(10*i+d)%13] += old_dp[i]
        else:
            new_dp[(10*i+int(c))%13] += old_dp[i]
    
    old_dp = [x % MOD for x in new_dp]
    new_dp = [0]*13
print(old_dp[5])