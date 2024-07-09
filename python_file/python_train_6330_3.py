MOD = 998244353

N = int(input())
A = [int(input()) for _ in range(N)]
SUM = sum(A)

dp = [ [0] * (SUM + 1) for _ in range(N+1) ]
dp2 = [ [0] * (SUM + 1) for _ in range(N+1) ]
# red [i][r] : rまで塗った
dp[0][0] = 1
dp2[0][0] = 1
for i in range(N):
    a = A[i]
    for r in range(0, SUM-a +1):
        #pick
        dp[i+1][r+a] = ( dp[i+1][r+a] + dp[i][r] ) % MOD
        dp2[i+1][r+a] = ( dp2[i+1][r+a] + dp2[i][r] ) % MOD


    for r in range(0, SUM + 1):
        # nopick    
        # B,G に入れる 2通り考える
        dp[i+1][r] = (dp[i+1][r] +  dp[i][r] * 2 ) % MOD
        dp2[i+1][r] = (dp2[i+1][r] +  dp2[i][r]  ) % MOD

if SUM % 2 ==0:
    notans = sum(dp[N][ SUM//2 : ]) * 3 % MOD

    notans = ( notans - 3 * dp2[N][SUM//2] ) %MOD
    cand = pow(3, N, MOD)

    print(  (cand - notans + MOD) % MOD  )
else:
    notans = sum(dp[N][ SUM//2 + 1: ]) * 3 % MOD
    cand = pow(3, N, MOD)
    print(  (cand - notans + MOD) % MOD  )

