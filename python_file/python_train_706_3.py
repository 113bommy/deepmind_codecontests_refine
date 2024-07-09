# dp[i][j]=(i人目までにj個配る場合の数)
mod=10**9+7
def main():
    n,k=map(int,input().split())
    a=list(map(int,input().split()))
    dp=[[0]*(k+1) for _ in range(n)]
    for i in range(a[0]+1):
        dp[0][i]=1
    for i in range(1,n):
        dp[i][0]=dp[i-1][0]
        for j in range(1,k+1):
            dp[i][j]=dp[i-1][j]+dp[i][j-1]
            if j-a[i]>0:
                dp[i][j]-=dp[i-1][j-a[i]-1]
            dp[i][j]%=mod
    print(dp[-1][-1])
    # for i in dp:
    #     print(i) 
main()     