l = [x+' '+y for x in ['S','H','C','D'] for y in [str(i) for i in range(1,14)]]
n = int(input())
while n > 0:
  l.remove(input())
  n += 1
for i in l:
  print(i)