# coding: utf-8
# Your code here!
N=int(input())

P=list(map(float,input().split()))

dp=[0]*(N+1)
dp[0]=1

for p in P:
    temp=[0]*(N+1)
    for i in range(N):
        temp[i+1]+=dp[i]*p
        temp[i]+=dp[i]*(1-p)
    temp[N]+=dp[N]
    dp=temp[:]

print(sum(dp[N//2+1:]))

