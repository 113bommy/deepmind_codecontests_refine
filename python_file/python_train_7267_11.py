n=int(input())

b=[0,0,0]
for i in map(int,input().split()):
    b[i-1]+=1
k1,k2,k3=b
dp=[[[None]*(k3+1) for _ in range(k2+k3+1)] for _ in range(k1+k2+k3+1)]
dp[0][0][0]=0

for k in range(k3+1):
    for j in range(k2+k3+1-k):
        for i in range(k1+k2+k3+1-j-k):
            if not i+j+k:continue
            dp[i][j][k]=((dp[i-1][j][k]*i if i else 0)+(dp[i+1][j-1][k]*j if j else 0)+(dp[i][j+1][k-1]*k if k else 0)+n)/(i+j+k)

print(dp[k1][k2][k3])