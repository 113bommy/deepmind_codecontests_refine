n = int(input())
a = [[] for i in range(n)]
for i in range(n):
    a[i] = list(map(int,input().split()))
    for j in range(n-1):
        a[i][j] -= 1
    a[i].reverse()
q = []

def check(i):
    if len(a[i]) == 0:
        return 
    j = a[i][-1]
    if len(a[j]) == 0:
        return
    if a[j][-1] == i:
        q.append([min(i,j), max(i,j)])
for i in range(n):
    check(i)
day = 0
while (len(q) > 0):
    day += 1
    prevQ = list(map(list, set(map(tuple, q))))
    q = []
    for i,j in prevQ:
        a[i].pop()
        a[j].pop()
        check(i)
        check(j)
for i in range(n):
    if len(a[i]) > 0:
        print(-1)
        exit()
print(day)