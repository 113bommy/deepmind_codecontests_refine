a,b,c=(int (x) for x in input().split())
for i in range(10):
  c=(a*c)-b
  print(c)