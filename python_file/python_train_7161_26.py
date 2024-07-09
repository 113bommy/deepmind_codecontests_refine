n,t = map(int,input().split())
now = [0 for _ in range(t+1)]
wv = []
for _ in range(n):
  wv.append(list(map(int,input().split())))
wv.sort(key=lambda x:x[0])
for i in range(n):
  w,v = wv[i]
  last = now
  now = []
  for f in range(t):
    if f - w >= 0:
      now.append(max(last[f],last[f-w]+v))
    else:
      now.append(last[f])
  now.append(max(last[-2]+v,last[-1]))
  #print(now)
print(now[-1])