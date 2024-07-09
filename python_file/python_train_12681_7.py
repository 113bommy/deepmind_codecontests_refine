s = input()
t = input()

H = len(s)
W = len(t)
dp = [[0 for x in range(W+1)] for y in range(H+1)]

for y in range(H) :
    for x in range(W) :
        if s[y] == t[x] :
            dp[y+1][x+1] = dp[y][x]+1
        else :
            dp[y+1][x+1] = max(dp[y+1][x], dp[y][x+1])

ans = ""

while (H > 0) and (W > 0) :
    if dp[H][W] == dp[H-1][W] :
        H -= 1
    elif dp[H][W] == dp[H][W-1] :
        W -= 1
    else :
        H -= 1
        W -= 1
        ans = s[H] + ans

print(ans)
