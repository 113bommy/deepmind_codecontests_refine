import sys
input = sys.stdin.readline

def main():
  l = int(input())
  dp = [[float('inf') for _ in range(l+1)] for _ in range(5)]
  dp[0][0] = 0
  for i in range(l):
    a = int(input())
    for j in range(5):
      for k in range(j, 5):
        cost = a
        if k == 1 or k == 3:
          if a % 2 == 0 and a > 0:
            cost = 0
          elif a > 0:
            cost = 1
          else:
            cost = 2
        elif k == 2:
          if a % 2 == 1:
            cost = 0
          else:
            cost = 1
        if dp[k][i+1] > dp[j][i] + cost:
          dp[k][i+1] = dp[j][i] + cost
  print(min([dpp[-1] for dpp in dp]))


if __name__ == '__main__':
  main()
