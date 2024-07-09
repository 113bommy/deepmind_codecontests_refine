N,ave = map(int,input().split())
card_ls = list(map(int, input().split()))
#dp[i+1][n][s] := i番目までのカード(0idx)からn枚使って合計がsとなるパターンの数
dp = [[[0]*(ave*N+1) for _ in range(N+1)] for _ in range(N+1)]
dp[0][0][0] = 1
for i in range(N):
    for n in range(N):
        for s in range(ave*N+1):
            # i番目を新しく使う
            if s+card_ls[i] < ave*N+1:
                dp[i+1][n+1][s+card_ls[i]] += dp[i][n][s]
            # i番目を使わない
            dp[i+1][n][s] += dp[i][n][s]

#print(dp)
ans = 0
for n in range(1,N+1):
    ans += dp[N][n][n*ave]
print(ans)