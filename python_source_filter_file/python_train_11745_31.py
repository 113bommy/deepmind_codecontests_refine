n,x=map(int,input().split())
a,p=[1],[1]
for i in range(n):
  a.append(a[-1]*2+3)
  p.append(p[-1]*2+1)
def f(n,x):
  if n==0:return+(x>0)
  elif x<=i+a[n-1]:return f(n-1,x-1)
  else:return p[n-1]+1+f(n-1,x-2-a[n-1])
print(f(n,x))