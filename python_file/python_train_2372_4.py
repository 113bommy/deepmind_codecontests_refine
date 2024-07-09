N = int(input())
S = input()

r= S.count("R")
g = S.count("G")
b= S.count("B")
ans=r*g*b

for j in range(N):
  for k in range(N):
    i=2*j-k
    if 0<=i<j<k<=N-1 and S[i]!=S[j] and S[i]!=S[k] and S[j]!=S[k]:
      ans-=1
print(ans)