n,c=map(int,input().split())
stc=[list(map(int,input().split())) for _ in range(n)]
cs_dc={}
dc={}
for s,t,c in stc:
  if c in dc:
    dc[c][s]+=1
    dc[c][t]-=1
  else:
    dc[c]=[0]*(10**5+2)
    dc[c][s]+=1
    dc[c][t]-=1
    cs_dc[c]=[0]*(10**5+2)

for i in range(10**5+1):
  for ci in dc:
    cs_dc[ci][i+1]=cs_dc[ci][i]+dc[ci][i+1]
ans=0
for i in range(10**5+1):
  tmp=0
  for ci in dc:
    tmp+=max(cs_dc[ci][i:i+2])
  ans=max(ans,tmp)
print(ans)