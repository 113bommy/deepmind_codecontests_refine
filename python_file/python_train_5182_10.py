N, K = map(int, input().split())
P = list(map(int, input().split()))
C = list(map(int, input().split()))

mx = [0] * N
cnts = [0] * N
for i in range(N):
  if mx[i] == 0:
    nxt = P[i]-1
    tmp = 0
    l = [nxt]
    for j in range(N):
      tmp += C[nxt]
      nxt = P[nxt]-1
      l.append(nxt)
      if nxt == i:
        tmp += C[nxt]
        cnt = j+2
        break
    for k in l:
      cnts[k] = cnt
      n = ((K//cnt)-1) * tmp
      if tmp > 0:
        mx[k] += n
    
for i in range(N):
  nxt = P[i]-1
  tmp = 0
  m = min(C) - 1
  for j in range((K%cnts[i])+cnts[i]):
    tmp += C[nxt]
    m = max(m, tmp)
    nxt = P[nxt]-1
  mx[i] += m

ans = max(mx)
print(ans)