h, w, k = map(int, input().split())
S = [list(map(int, list(input()))) for _ in range(h)]
ans = float("inf")
for i in range(2**(h-1)):
  L = [0]
  cnt = 0
  for j in range(h-1):
    if i>>j & 1:
      L.append(j+1)
      cnt += 1
  L.append(h)
  C = [0]*(len(L)-1)
  for j in range(w):
    D = [0]*(len(L)-1)
    for l in range(len(L)-1):
      a, b = L[l], L[l+1]
      for s in range(a, b):
        D[l] += S[s][j]
    if max(D) > k:
      break
    for l, d in enumerate(D):
      if C[l]+d > k:
        break
    else:
      for l, d in enumerate(D):
        C[l] += d
      continue
    cnt += 1
    for l, d in enumerate(D):
      C[l] = d
  else:
    ans = min(ans, cnt)
print(ans)