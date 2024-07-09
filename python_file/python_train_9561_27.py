N, K = map(int, input().split())
xy = [list(map(int, input().split())) for _ in range(N)]

ans = float('inf')
for i in range(N):
  for j in range(N):
    for k in range(N):
      for l in range(N):
        x1= xy[i][0]
        x2 = xy[j][0]
        y1 = xy[k][1]
        y2 = xy[l][1]
        cnt = 0
        if x1 < x2 and y1 < y2:
          for n in range(N):
            if x1 <= xy[n][0] <= x2 and y1 <= xy[n][1] <= y2:
              cnt += 1

          if cnt >= K:
            ans = min(ans, (x2-x1)*(y2-y1))
print(ans)