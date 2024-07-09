n,m =map(int,input().split())

maxnum = m//n

for i in range(maxnum,0,-1):
  if m%i==0:
    print(i)
    break
  