N = int(input())
ab = []
abn = [0]*N
abw = [[] for _ in range(N)]
for i in range(N-1):
  a,b = list(map(int,input().split()))
  ab.append([a,b])
  abw[a-1].append(b)
  abw[b-1].append(a)
  abn[a-1] += 1
  abn[b-1] += 1
c = sorted(list(map(int,input().split())))
cn = 0
d = [0]*N
s = [i for i in range(N)]
while cn <N:
  cut = []
  for i in s:
    if (abn[i] == 1 and cn<N) or len(s) == 1:
      d[i] = c[cn]
      cn += 1
      cut.append(i)
      abn[i] -=1
      s.remove(i)
  for j in cut:
    for k in abw[j]:
      abn[k-1] -= 1
print(sum(c)-max(c))
print(" ".join(map(str,d)))