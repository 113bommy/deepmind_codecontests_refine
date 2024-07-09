#E
H,N=map(int,input().split())

A=[]
B=[]
DP=[0]+[float('Inf')]*(2*10**4)

for i in range(N): 
  a,b=map(int,input().split())
  A.append(a)
  B.append(b)

for j in range(10**4):
  for i in range(N):
    DP[j+A[i]]=min(B[i]+DP[j],DP[j+A[i]])

print(min(DP[H:]))