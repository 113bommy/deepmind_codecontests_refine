s = input()
if s[0] == s[-1]:
  if len(s) % 2 == 1:
    print("Second")
  else:
    print("First")
else:
  if len(s) % 2 == 0:
    print("First")
  else:
    print("Second")