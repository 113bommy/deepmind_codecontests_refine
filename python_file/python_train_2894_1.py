n,q = map(int, input().split())
ab = [list(map(int, input().split())) for i in range(n-1)]
px = [list(map(int, input().split())) for i in range(q)]
parent = [0] * n
ans = [0] * n

for i in ab:
  a,b=i[0],i[1]
  parent[b-1] = a-1
  
for j in px:
  p,x = j[0], j[1]
  ans[p-1] += x

for key, i in enumerate(ans[1:]):
  key += 1
  ans[key] += ans[parent[key]]
print(*ans)
