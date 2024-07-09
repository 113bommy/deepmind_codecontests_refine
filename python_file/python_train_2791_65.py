n, k = [int(e) for e in input().split()]
arr = [int(e) for e in input().split()]
dp = [0]*len(arr)
 
for i in range(1,len(arr)):
  dp[i] = min(dp[j] + abs(arr[i]-arr[j]) for j in range(max(i-k,0),i))
print(dp[-1])

