def gcd(a,b):
  if a%b==0:
    return b
  else:
    return gcd(b,a%b)
N,X=map(int,input().split())
print(3*(N-gcd(N,X)))
