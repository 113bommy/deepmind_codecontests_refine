n,k=map(int,input().split())
a=list(map(int,input().split()))
dp=[False for i in range(k+1)]
for i in range(k+1):
    for j in range(n):
        if i-a[j]>=0:
            dp[i]|=(dp[i-a[j]]^(True))
if dp[k]:
    print("First")
else:
    print("Second")