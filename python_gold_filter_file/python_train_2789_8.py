N = int(input())
d = [int(x) for x in input().split()]

f = sum(d)
s = 0

for i in d:
  s += i * (f-i)
print(s//2)
     