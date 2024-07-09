n=int(input())
a=[int(x) for x in input().split()]
ma=max(a)
memo=[0]*ma

def gcd(a,b):#最大公約数
  while b!=0:
    a,b=b,a%b
  return a

for i in a:
  memo[i-1]+=1

pair=True
for i in range(2,ma+1):
  cnt=0
  for j in range(i,ma+1,i):
    if 0<memo[j-1]:
      cnt+=1
  if 1<cnt:
    pair=False


g=a[0]
for i in range(1,n):
  g=gcd(g,a[i])

if pair == False and g==1:
  print("setwise coprime")
elif pair == True and g==1:
  print("pairwise coprime")
else:
  print("not coprime")
    