s = input()
t = input()

ls = len(s)
lt = len(t)
ans = ""
dp = [[0]*(lt+1) for i in range(ls+1)]

for i in range(1,ls+1):
    for j in range(1,lt+1):
        if s[i-1] == t[j-1]:
            dp[i][j] = dp[i-1][j-1] + 1
        else:
            dp[i][j] = max(dp[i-1][j], dp[i][j-1])

x = lt
y = ls

while x-1>=0 and y-1>=0:
    if dp[y][x] == dp[y][x-1]:
        x -= 1
    elif dp[y][x] == dp[y-1][x]:
        y -= 1
    else:
        ans = s[y-1] + ans
        x -= 1
        y -= 1

print(ans)