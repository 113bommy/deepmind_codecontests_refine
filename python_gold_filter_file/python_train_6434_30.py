N,M = map(int,input().split())
L1 = 0
R1 = N

for m in range(M):
  L2,R2 = map(int,input().split())
  L1 = max(L1,L2)
  R1 = min(R1,R2)
  
print(max(0,R1-L1+1))