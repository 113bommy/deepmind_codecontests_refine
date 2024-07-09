s = str(input())
t = str(input())

dp=[[0 for i in range(len(s)+1)] for j in range(len(t)+1)] 

for i in range(1,len(s)+1):
    for u in range(1,len(t)+1):
        if s[i-1]==t[u-1]:
            dp[u][i]=dp[u-1][i-1]+1
        else:
            dp[u][i]=max(dp[u-1][i],dp[u][i-1])
lenth=dp[-1][-1]
i=len(s)
j=len(t)
ans=""
while lenth>0:
    if s[i-1]==t[j-1]:
        ans=s[i-1]+ans
        i-=1
        j-=1
        lenth-=1
    elif dp[j][i]==dp[j-1][i]:
        j-=1
    else:
        i-=1
    lenth=dp[j][i]
print(ans)