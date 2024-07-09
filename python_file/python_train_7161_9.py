#16:25
n,t = map(int,input().split())
wv = []
for _ in range(n):
  wv.append(list(map(int,input().split())))
wv.sort(key=lambda x:x[0])
now = [0 for _ in range(t+1)]
for i in range(n):
  w,v = wv[i]
  last = now
  now = []
  for f in range(t):
    if f >= w:
      now.append(max(last[f-w]+v,last[f]))
    else:
      now.append(last[f])
  now.append(max(last[-2]+v,last[-1]))
print(now[-1])