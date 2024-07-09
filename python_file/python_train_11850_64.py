n,m = map(int,input().split())

max_num = int(m/n)
ans = -1
for i in reversed(range(max_num + 1)):
  if(m % i == 0):
    ans = i
    break

print(ans)