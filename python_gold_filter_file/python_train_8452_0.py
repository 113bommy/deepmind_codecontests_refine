t = int(input())
for i in range(t):
  n,x,a,b = map(int,input().split())
  print(min(n-1,x+abs(a-b)))