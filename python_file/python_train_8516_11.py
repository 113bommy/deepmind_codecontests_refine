import sys
input=sys.stdin.readline

n=int(input())
s=[ord(i)for i in input()]
t=[-1]*n
for i in range(n):
  if s[i]==68:
    t[i]=0
  elif s[i]==77:t[i]=1
  elif s[i]==67:t[i]=2

def solve(k):
  dd=mm=dm=dmc=0
  for i in range(n):
    if t[i]==0:dd+=1
    if i>=k and t[i-k]==0:dm-=mm;dd-=1
    if t[i]==1:dm+=dd;mm+=1
    if i>=k and t[i-k]==1:mm-=1
    if t[i]==2:dmc+=dm
  return dmc

q=int(input())
k=list(map(int,input().split()))
for i in k:print(solve(i))