from collections import deque

n,x = map(int, input().split())
a = list(map(int, input().split()))

def slide(a, k):
  q = deque()
  ans = 0
  for i in range(-k,0):
    while q and a[q[-1]] > a[i]: q.pop()
    q.append(i)
  for i in range(n):
    if q[0] <= i-k: q.popleft()
    while q and a[q[-1]] > a[i]: q.pop()
    q.append(i)
    ans += a[q[0]]
  return ans

print(min(slide(a,k+1) + x*k for k in range(n)))