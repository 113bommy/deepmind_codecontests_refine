X,Y,Z,K=map(int, input().split())
A=list(map(int, input().split()))
B=list(map(int, input().split()))
C=list(map(int, input().split()))
D=[]
for i in A:
  for j in B:
    D.append(i+j)
D=sorted(D)[::-1]
if X*Y>K:
  D=D[:K]
E=[]
for i in D:
  for j in C:
    E.append(i+j)
E=sorted(E)[::-1]
E=E[:K]
for i in E:
  print(i)