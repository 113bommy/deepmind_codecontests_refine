N = int(input())
Ts = list(map(int, input().split()))
M = int(input())
for i in range(M):
  p, x = map(int, input().split())
  print(sum(Ts)-T[p-1]+x)