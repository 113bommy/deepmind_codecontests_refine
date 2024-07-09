import bisect

n,m=map(int,input().split())
a=sorted(list(map(int,input().split())))
for i in range(m):
  t=a[-1]
  t//=2
  a.pop()
  bisect.insort_left(a,t)
  #print(i,a)
print(sum(a))
