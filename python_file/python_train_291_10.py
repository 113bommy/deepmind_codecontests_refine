import sys

sys.setrecursionlimit(4100000)

def func(array, arr, d):
  for v in arr:
    if array[v[0]] == None:
      d1 = d + v[1]
      array[v[0]] = d1
      arr1 = dic.get(v[0], [])
      
      if not func(array, arr1, d1):
        return False
      
    elif array[v[0]] != d + v[1]:
      return False
    
  return True
      

n,m = map(int, input().split())

array = [None] * n
dic = {}

for i in range(m):
  l,r,d = map(int, input().split())
  l -= 1
  r -= 1
  
  dic.setdefault(l,[])
  dic.setdefault(r,[])
  dic[l].append((r,d))
  dic[r].append((l,-d))
  
for i in range(n):
  if array[i] != None:
    continue
    
  array[i] = 0
  arr = dic.get(i, [])
  
  if not func(array, arr, 0):
    print('No')
    sys.exit()

print('Yes')    