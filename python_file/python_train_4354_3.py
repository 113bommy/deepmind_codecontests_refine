import sys
input=sys.stdin.readline
def chmax(a,b):
    if a>=b:
        return a
    return b
def chmin(a,b):
    if a<=b:
        return a
    return b
def main():
    N=int(input())
    a=list(map(int,input().split()))
    dp=[[0]*(N+2) for _ in range(N+2)]
    for len in range(1,N+1):
        for i in range(N+1-len):
            j=i+len
            if (N-len)%2==0:
                dp[i][j]=chmax(dp[i+1][j]+a[i],dp[i][j-1]+a[j-1])
            else:
                dp[i][j]=chmin(dp[i+1][j]-a[i],dp[i][j-1]-a[j-1])
    print(dp[0][N])
main()