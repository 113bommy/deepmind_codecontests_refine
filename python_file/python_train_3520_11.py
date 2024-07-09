import sys
sys.setrecursionlimit(10**7)
def main():
  def s(l,r):
    k=l*n+r
    if d[k]:return d[k]
    if r-l<2:return 0
    d[k]=t=min(s(l,i)+s(i,r)for i in range(l+1,r))+a[r-1]-a[l-1]
    return t
  n,*a=map(int,open(0).read().split())
  d=[None]*(n*n+1)
  for i in range(n-1):a[i+1]+=a[i]
  a+=[0]
  print(s(0,n))
main()