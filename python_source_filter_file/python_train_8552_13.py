u = int( input() )
a = list(map(int, input().split()))
f = 0
for i in range(u):
    if a[i] != a[i+1]:
        f = 1
if f == 0:
    print('-1')
else:
    a.sort()
    print(*a) 

