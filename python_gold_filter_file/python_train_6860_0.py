for e in iter(input,'0 0'):
 N,M=map(int,e.split())
 k,p=1,0
 S=[int(input()) for _ in[0]*N]
 for d in[int(input())for _ in[0]*M]:
  p+=d if N<=p+d else d+S[p+d]
  if N<=p+1:break
  k+=1
 print(k)
