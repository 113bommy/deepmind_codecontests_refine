N = int(input())
S = input()
ans = S.count('R') * S.count('G') * S.count('B')
for i in range(N):
  for j in range(i, N):
    k = 2*j - i
    if k >= N:
      break
    if len(set([S[i], S[j],S[k]])) ==3:
      ans -= 1
print(ans)