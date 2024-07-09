import sys
input = sys.stdin.readline
rev=0
ST=""
EN=""
S=input()
Q=int(input())
for i in [0]*Q:
 A=list(input().split())
 if int(A[0])==1 :
  rev+=1
 else:
  if (int(A[1])+rev)%2==1:
   ST+=A[2]
  else:
   EN+=A[2]
if rev%2==0:
 print(ST[::-1].strip()+S.strip()+EN.strip())
else:
 print(EN[::-1].strip()+S[::-1].strip()+ST.strip())
