n=int(input())

def dfs(s):
  if n<int(s) : return 0
  res = if all(s.count(c)>0 for c in "753") : 1 else 0
  for i in "753":
    res += dfs(s+i)
  return res

print(dfs("0"))
