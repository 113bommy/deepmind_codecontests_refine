A,B,C = map(int,input().split())
a = "NO"

for n in range(101):
  if n%A==0 and n%B==C:
    a = "YES"

print(a)