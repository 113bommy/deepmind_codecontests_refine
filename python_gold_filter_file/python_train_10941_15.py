abc = 1000001
ab  = 1000001
bc  = 1000001
ac  = 1000001
a   = 1000001
b   = 1000001
c   = 1000001
aa = bb = cc = 0

n = int(input())
while n > 0:
  e = input().split()
  #print(e)
  vl = int(e[0])
  vit = sorted(e[1])
  vt = ""
  for i in vit:
    vt += i
  
  #print(vt)
  if vt == "ABC":
    aa = bb = cc = 1
    if abc > vl:
      abc = vl

  elif vt == "AB":
    aa = bb = 1
    if ab > vl:
      ab = vl

  elif vt == "BC":
    bb = cc = 1
    if bc > vl:
      bc = vl

  elif vt == "AC":
    aa = cc = 1
    if ac > vl:
      ac = vl

  elif vt == "A":
    aa = 1
    if a > vl:
      a = vl
  elif vt == "B":
    bb = 1
    if b > vl:
      b = vl

  else: #C
    cc = 1
    if c > vl:
      c = vl
  n -= 1

if aa + bb + cc == 3:
  l = [abc, ab+c, a+bc, ac+b, a+b+c, ab+bc, ac+bc, ac+ab]
  print(min(l))
else:
  print(-1)