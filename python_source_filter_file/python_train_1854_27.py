S=input()
for i in range(3):
  if s[i]==s[i+1]:
    print('Bad')
    exit(0)
print('Good')