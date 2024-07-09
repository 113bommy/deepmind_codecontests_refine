N = int(input())

memo1 = []
memo2 = []
for i in range(N):
  S = input()
  sum_n = min_n = 0
  for s in S:
    if s == ')':
      sum_n -= 1
      min_n = min(min_n, sum_n)
    else:
      sum_n += 1
  if sum_n >= 0:
    memo1.append([min_n, sum_n])
  else:
    memo2.append([min_n-sum_n, -sum_n])

memo1.sort(reverse=True)
left = 0
for min_n, sum_n in memo1:
  if left + min_n < 0:
    print('No')
    quit()
  else:
    left += sum_n

memo2.sort(reverse=True)
right = 0
for min_n, sum_n in memo2:
  if right + min_n < 0:
    print('No')
    quit()
  else:
    right += sum_n

if left == right:
  print('Yes')
else:
  print('No')