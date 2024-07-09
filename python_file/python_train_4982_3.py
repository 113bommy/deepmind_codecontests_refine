N, K = map(int, input().split())
A = list(map(int, input().split()))
B = []
for a in A:
  if a < K:
    B.append(a)

N = len(B)
B.sort(reverse=True)
check = [True] + [False]*N
dp = [[False]*(K+1) for i in range(N+1)]
dp[0][0] = True
for i, b in enumerate(B, 1):
  for j in range(K+1):
    dp[i][j] = dp[i-1][j]
    if K-b <= j <= K - 1 and dp[i][j]:
      check[i] = True
    if j >= b and dp[i-1][j-b]:
      dp[i][j] = True

ans = 0
for i in range(N, -1, -1):
  if check[i]:
    break
  ans += 1

print(ans)