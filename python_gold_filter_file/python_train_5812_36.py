N,T=map(int,input().split())

m=1001
for i in range(N):
  c,t=map(int,input().split())
  if t<=T and c<m:
    m=c
print(m if m!=1001 else "TLE")
