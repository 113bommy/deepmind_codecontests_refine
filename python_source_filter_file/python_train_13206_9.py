s = input()
ans = 0

for i in range(len(s)-1):
  if s[i] != S[i+1]:
    ans += 1

print(ans)