import sys
n=int(input())
s=[list(input()) for i in range(n)]
L1=[]
L2=[]
ct1=0;ct2=0
for i in range(n):
  ct3=0
  l=[0]
  for j in range(len(s[i])):
    if s[i][j]=='(':
      ct1+=1
      ct3+=1
      l.append(ct3)
    else:
      ct2+=1
      ct3-=1
      l.append(ct3)
  if l[-1]>=0:
    L1.append((min(l),l[-1]))
  else:
    L2.append((min(l)-l[-1],-l[-1]))
if ct1!=ct2:
  print('No')
  sys.exit()

L1.sort()
L1.reverse()
ct4=0
for i in range(len(L1)):
  if ct4+L1[i][0]<0:
    print('No')
    sys.exit()
  ct4+=L1[i][1]

L2.sort()
L2.reverse()
ct5=0
for i in range(len(L2)):
  if ct5+L2[i][0]<0:
    print('No')
    sys.exit()
  ct5+=L2[i][1]

print('Yes')