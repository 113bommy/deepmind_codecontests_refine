x = input()
c = 0
for i in x:
  if x == "S":
    c += 1
  elif c>0:
    c -= 1
print(2*c)
  