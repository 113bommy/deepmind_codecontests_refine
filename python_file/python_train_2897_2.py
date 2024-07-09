from itertools import combinations, product
n=int(input())
s=[["a" for _ in range(n)] for _ in range(n)]
for i in range(n):
  s[i]=list(input())

res=0
for a in range(n):
  for i,j in combinations(range(n),2):
    if(s[(i+a)%n][j%n]!=s[(j+a)%n][i%n]):
      break
  else:
    res+=1

print(res*n)
