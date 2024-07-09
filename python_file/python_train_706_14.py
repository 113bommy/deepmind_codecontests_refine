import sys
MOD=10**9+7
def solve(N:int,K:int,A:list)->int:
    #dp[i][j]:=i人目までの子供にj個の飴を配る場合の数
    dp=[[0]*(K+1) for i in range(N+1)]
    for i in range(N):dp[i][0]=1
    sum=[0]*(K+2)
    for i in range(N):
        for j in range(K+1):#累積和
            sum[j+1]=(sum[j]+dp[i][j])%MOD
        for j in range(K+1):
            dp[i+1][j]=(sum[j+1]-sum[max(0,j-A[i])]+MOD)%MOD
            dp[i+1][j]%=MOD
    return dp[N][K]
def main(lines):
    N,K=map(int,lines[0].split())
    A=list(map(int,lines[1].split()))
    print(solve(N,K,A))
if __name__ == '__main__':
    lines = []
    for l in sys.stdin:
        lines.append(l.rstrip('\r\n'))
    main(lines)
