n, m = map(int, input().split())
s = set(str(i) for i in range(m))
for _ in range(n):
  s = s & set(input().split()[1:])
print(len(s))