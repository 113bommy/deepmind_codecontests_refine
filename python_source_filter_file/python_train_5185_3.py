n,d = map(int,input().split())
x = [list(map(int,input().split())) for a in range(n)]
c = 0
 
for i in range(n-1):
  for j in range(i+1,n):
    b = 0
    for m in range(d):
      b += (x[i][m]-x[j][m])**2
    if (b**0.5)　== float(int(b**0.5)):
      c += 1
      
print(c)