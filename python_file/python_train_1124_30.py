N,Q = map(int,input().split())
s = input()
L = []
for i in range(Q):
  L.append(list(input().split()))
def judge_left(x):
  for i in range(Q):
    if L[i][0] == s[x]:
      if L[i][1] == 'L':
        x -= 1
      else:
        x += 1
    if x == -1:
      return True
    if x == N:
      return False
  return False
def judge_right(x):
  for i in range(Q):
    if L[i][0] == s[x]:
      if L[i][1] == 'L':
        x -= 1
      else:
        x += 1
    if x == -1:
      return False
    if x == N:
      return True
  return False
ok = -1
ng = N
while ng-ok > 1:
  mid = (ng+ok)//2
  if judge_left(mid):
    ok = mid
  else:
    ng = mid
left = ok+1

ok = N
ng = -1
while ok-ng > 1:
  mid = (ng+ok)//2
  if judge_right(mid):
    ok = mid
  else:
    ng = mid
right = N-ok
print(max(N-left-right,0))