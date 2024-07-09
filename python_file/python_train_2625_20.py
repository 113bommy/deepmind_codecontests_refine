for _ in range(int(input())):
    n,p,k=map(int,input().split())
    arr=list(map(int,input().split()))
    arr.sort()
    dp=[0]*n
    ans=0
    for i in range(n):
        if i>k-1:
            dp[i]=dp[i-k]+arr[i]
        else:
            dp[i]=arr[i]
        if dp[i]>p:
            ans=i
            break
        if i==n-1:
            ans=n
            break
    print(ans)