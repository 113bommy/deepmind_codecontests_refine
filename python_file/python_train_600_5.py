import sys
input = sys.stdin.readline

n,m = map(int, input().split())
t = sorted([tuple(map(int, input().split())) for i in range(m)])
d=[0,0]+[1e18]*n
for l,r,c in t:
  for i in range(r,l,-1):
    if d[l]+c<d[i]:
      d[i]=d[l]+c
    else:
      break
print(d[-2]%10**18or-1)