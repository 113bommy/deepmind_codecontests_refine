input();s=input();a=set(s)
a=1
for i in a:ans=ans*(s.count(i)+1)%(10**9+7)
print(a-1)