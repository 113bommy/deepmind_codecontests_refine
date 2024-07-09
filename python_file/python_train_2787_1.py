def P(s):
  L = [0] * 26
  R = P = 0
  for i in range(D):
    t = I[i + D][0] - 1
    R += I[i][t]
    P += s - (i + 1 - L[t]) * C[t]
    R -= P
    L[t] = i + 1
  return R
(D,), C, *I = [list(map(int, o.split())) for o in open(0)]
for d, q in I[2*D + 1:]:
  I[d - 1 + D][0] = q
  print(P(sum(C)))