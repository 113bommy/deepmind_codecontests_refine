r = 0
s = input()
for n in range(len(s)):
  if s[n] != s[(-1)*(n+1)]:
    r += 1
print(r/2)