N = int(input())
a = [int(x) for x in input().split()]

cumsum = [0] * N
cumsum[0] = a[0]
for i in range(1, N):
    cumsum[i] = cumsum[i-1] + a[i]

dp = [[0] * N for _ in range(N)]

for j in range(1, N):
    for i in range(N-1):
        if i + j >= N:
            break
        minimum = float('inf')
        for k in range(j):
            #print('i:',i,' j:',j,' k:',k,' i+k:',i+k,' j-k:',j-k)
            temp = dp[i][k] + dp[i+k+1][j-k-1]
            if minimum > temp:
                minimum = temp
        dp[i][j] = minimum + (cumsum[i+j] - cumsum[i-1] if i > 0 else cumsum[i+j])

print(dp[0][N-1])