N = int(input())
A = list(map(int, input().split()))

cum = [[0]*(N) for i in range(N)]
for i in range(N):
  c = 0
  for j in range(i, N):
    c += A[j]
    cum[i][j] = c

dp = [[0]*N for i in range(N)]

def get_min_cost(i, j):
  global dp
  if dp[i][j] > 0:
    return dp[i][j]
  else:
    min_cost = 0
    for k in range(i, j):
      if min_cost == 0:
        min_cost = get_min_cost(i, k) + get_min_cost(k+1, j) + cum[i][j]
      else:
        cost = get_min_cost(i, k) + get_min_cost(k+1, j) + cum[i][j]
        min_cost = min(min_cost, cost)
    
    dp[i][j] = min_cost
    return dp[i][j]

print(get_min_cost(0, N-1))