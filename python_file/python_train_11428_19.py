import math
import sys
pin=sys.stdin.readline

def main():
  N,X,M=map(int,pin().split())
  A=X
  d=[X]
  su=X
  for i in range(N-1):
    A=(A**2)%M
    if A in d:
      t=d.index(A)
      T=N-i-1
      d=d[t:]
      l=len(d)
      su+=sum(d)*(T//l)
      T=T%(T//l)
      su+=sum(d[:T])
      print(su)
      return
    d.append(A)
    su+=A
  print(su)
  return
main()