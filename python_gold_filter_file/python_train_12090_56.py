T = int(input())
ansL = []
for i in range(T):
  x, y = map(int, input().split())
  ansL.append(x)
for j in ansL:
  print(j, 2*j)