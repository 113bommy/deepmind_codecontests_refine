n = int(input())
a = list(map(int,input().split()))
k = 1
for d in a:
  if d%2 == 0:
    k *= 2
print(3**n-k)
