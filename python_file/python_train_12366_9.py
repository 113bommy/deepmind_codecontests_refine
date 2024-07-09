H, W, K = map(int, input().split())
S = [input() for _ in range(H)]
d = 2 ** (H - 1)
mcut = 1008
for i in range(d):
  L = [0 for _ in range(H)]
  for j in range(1, H):
    L[j] = L[j-1] + i % 2
    i //= 2
  C = [0 for _ in range(L[H-1]+1)]
  cutp, cutq = True, True
  cut = L[H-1]
  for m in range(W):
    for l in range(H):
      C[L[l]] += int(S[l][m])
    if cutq:
      cutq = False
      if max(C) > K:
        cutp = False
        break
    else:
      if max(C) > K:
        cut += 1
        C = [0 for _ in range(L[H-1]+1)]
        for l in range(H):
          C[L[l]] += int(S[l][m])
    if cutp == False:
      break
  if cutp:
    if cut < mcut:
      mcut = cut
print(mcut)