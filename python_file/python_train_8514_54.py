s=input()
t=input()
if len(set(t)-set(s))>0:
  print(-1)
  exit()

ss=s*2
ind=-1
ans=0
for c in t:
  nex=ss[ind+1:].find(c)
  ind=(ind+1)+nex
  if ind>=len(s):
    ind-=len(s)
    ans+=len(s)

print(ans+ind+1)
