def main():
    import sys
    input=sys.stdin.readline
    n=int(input())
    A=[list(map(int,input().split())) for i in range(n)]
    mod=10**9+7

    dp=[0]*(1<<n)
    dp[0]=1
    for s in range(1<<n):
        i=format(s,'b').count('1')
        for j in range(n):
            if (s>>j)&1 and A[i-1][j]==1:
              dp[s]+=dp[s^(1<<j)]
              dp[s]%=mod   
              
    print(dp[-1])
if __name__=='__main__':
    main()