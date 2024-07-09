import sys
readline = sys.stdin.readline

N =  int(readline())
HP = [tuple(map(int, readline().split())) for _ in range(N)]
HP.sort(key = lambda x: x[0] + x[1])
INF = 1<<64

dp = [0]
for i in range(N):
    hi, pi = HP[i]
    dp += [INF]
    for j in range(i+1, 0, -1):
        if dp[j-1] > hi:
            continue
        dp[j] = min(dp[j], dp[j-1]+pi)
for ans in range(N+1):
    if dp[ans] == INF:
        ans -= 1
        break
print(ans)

