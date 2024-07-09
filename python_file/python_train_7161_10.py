# coding: utf-8
# Your code here!
N,T=map(int,input().split())

l=[]
for _ in range(N):
    a,b=map(int,input().split())
    l.append([a,b])

l.sort()

dp=[-1]*(6001)
dp[0]=0

for cand in l:
    for i in range(T)[::-1]:
        if dp[i]!=-1:
            dp[i+cand[0]]=max(dp[i+cand[0]],dp[i]+cand[1])
print(max(dp))

