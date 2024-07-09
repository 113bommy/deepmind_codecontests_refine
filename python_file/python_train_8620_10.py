mod = 10 **9 + 7



n = int(input())
match_list = []
for i in range(n):
    match_list.append(list(map(int, input().split())))
    
    
c = [0]
for i in range(n):
    c += [j+1 for j in c]


dp = [0] * (1 << n)
dp[0] = 1
for i in range((1 << n)-1):
    for j in range(n):
        if match_list[c[i]][j]:
            dp[(1<<j)^i] = (dp[(1<<j)^i] + dp[i])%mod


print(dp[-1])