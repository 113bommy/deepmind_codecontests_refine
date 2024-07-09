n,k=map(int, input().split())
a=list(map(int, input().split()))
x=[1]
dp=[0]*(k+1)
#先手勝利1

for i in range(1,k+1):
    for j in range(n):
        if i>=a[j]:
            x.append(dp[i-a[j]])
    if min(x)==0:
        dp[i]=1
    else:
        dp[i]=0
    x=[1]
if dp[k]==1:
    print('First')
else:
    print('Second')