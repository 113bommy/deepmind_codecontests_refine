n = int(input())
s = input()
ans = 0
for i in range(1000):
  a = [i//100, (i//10)%10, i%10]
  cnt = 0
  for j in range(n):
    if cnt <= 2 and a[cnt] == int(s[j]): cnt+=1
  if cnt == 3: ans += 1
print(ans)