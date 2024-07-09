N = int(input())
S = input()

ans = S.count('R') * S.count('G') * S.count('B')
for i in range(N):
  for j in range(i+1,N):
    if (i+j)%2 :
      continue
    k = (i+j)//2
    if len(set([S[i],S[k],S[j]])) == 3:
      ans -= 1
      
print(ans)