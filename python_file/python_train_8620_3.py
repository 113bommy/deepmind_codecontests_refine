def main():
  n = int(input())
  mod = 10**9+7
  a = []
  for i in range(n):
    a.extend(list(map(int,input().split())))
  dp = [0]*(1<<n)
  dp[0] = 1
  for S in range((1<<n)-1):
    k = bin(S).count("1")*n
    t = dp[S]
    for i in range(n):
      if a[k+i]:
        dp[S|1<<i] = (dp[S|1<<i]+t)%mod
  print(dp[(1<<n)-1])
main()