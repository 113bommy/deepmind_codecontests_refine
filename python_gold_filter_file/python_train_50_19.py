n,m=[int(x) for x in input().split()]
l=[0]
for i in range(n):
    s=[int(x) for x in input().split()]
    if s[0]!=0:
        for j in range(s[0]):
            l.append(s[j+1])
t=1
for i in range(m+1):
    if i not in l:
        t=0
if t==1:
    print('YES')
else:
    print('NO')