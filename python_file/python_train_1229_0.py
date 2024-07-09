N,K = map(int,input().split())
A = list(map(int,input().split()))

dp = [False]*(K+1)

for i in range(K+1):
    for j in range(N):
        if i-A[j]>=0 and dp[i-A[j]] == False:
            dp[i] = True

        
if dp[K]:
    print("First")
else:
    print("Second")