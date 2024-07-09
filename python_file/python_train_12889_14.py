n,W = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(n)]
inf = float('INF')
bag = [inf for _ in range(10**5+1)]
bag[0] = 0

ans = 0
for w,v in a:
  for i in range(min(v,10**5+1), 10**5+1)[::-1]:
    if bag[i-v] + w < min(bag[i],W+1):
        bag[i] = bag[i-v] + w
        ans = max(ans, i)
print(ans)
