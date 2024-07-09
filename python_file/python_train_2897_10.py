N = int(input())
S = []
for i in range(N):
  Ss = input()
  S.append(Ss)
r = 0
for i in range(N):
  T = S[i:]+S[:i]
  ok = True
  for i in range(N):
    for j in range(i+1, N):
      if T[i][j] != T[j][i]:
        ok = False
        break
  if ok:
    r += 1
r *= N
print(r)
