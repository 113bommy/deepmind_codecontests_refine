input()
s=input()
a=1
for i in set(s):a*=s.count(i)+1
print(a%(10**9+9)-1)