s=input()
c=0
while len(s)>1:
  if s[0]==s[len(s)-1]:
    s=s[1:len(s)-1]
  elif s[0]=='x':
    c+=1
    s=s[1:]
  elif s[len(s)-1]=='x':
    c+=1
    s=s[:len(s)-1]
  else:
    print(-1)
    exit()
print(c)