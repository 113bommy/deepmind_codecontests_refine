n = int(input())
a = list(map(int,input().split()))
mi = 0
for i in range(a):
  if a[i] < 0:
    mi+=1
  a[i]= abs(a[i])
if mi %2 == 1:
  print(sum(a)-min(a))
else:
  print(sum(a))