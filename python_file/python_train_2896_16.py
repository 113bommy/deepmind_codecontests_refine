from itertools import accumulate,combinations
n,k = map(int,input().split())
a = list(map(int,input().split()))
acc = [0]+list(accumulate(a))
ls = []
for i,j in combinations(acc,2):
  ls.append(j-i)
x = max(ls).bit_length()
ans = 0
for i in range(x-1,-1,-1):
  cnt = 0
  for j in ls:
    if ans+2**i & j == ans+2**i:
      cnt += 1
  if cnt >= k:
    ans += 2**i
print(ans)