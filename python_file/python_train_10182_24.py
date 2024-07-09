# 新ステージでは、一度全部どんぐりに直してから換金を始めるとしてよい

def F(N, A, B):
  # N個のどんぐりを、Aで換金してからBに持っていく
  # Bでどんぐりに直す
  dp = [0] * (N+1)
  for n in range(N+1):
    x = n
    for j in range(3):
      if n >= A[j]:
        y = dp[n-A[j]] + B[j]
        if x < y:
          x = y
    dp[n] = x
  return dp[N]

N = int(input())
A = [int(x) for x in input().split()]
B = [int(x) for x in input().split()]

answer = F(F(N,A,B),B,A)
print(answer)