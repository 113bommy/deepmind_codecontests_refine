N = int(input())
S = []
for i in range(N):
  Ss = input()
  S.append(Ss)
E = [set() for i in range(N)]
D = [[100000]*N for i in range(N)]
for i in range(N):
  D[i][i] = 0
  for j in range(i+1, N):
    if S[i][j] == "1":
      #print(i, j)
      E[i].add(j)
      E[j].add(i)
      D[i][j] = 1
      D[j][i] = 1
ok = True
V = [-1]*N
c = 0
V[0] = 0
q = [0]
while q:
  c = q.pop()
  ns = E[c]
  for n in ns:
    if V[n] == V[c]:
      ok = False
    if not V[n] < 0:
      continue
    V[n] = 1 if V[c] == 0 else 0
    q.append(n)
if not ok:
  print(-1)
  exit()
for k in range(N):
  for i in range(N):
    for j in range(N):
      D[i][j] = min(D[i][j], D[i][k]+D[k][j])
#print(D)
r = max([max(Ds) for Ds in D])+1
print(r)
