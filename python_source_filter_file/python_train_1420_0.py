n = int(input())
#n, m = map(int, input().split())
#s = input()
c = list(map(int, input().split()))
p = set()
a = []
b = []
for i in c:
    if i in p:
        a[b.index(i)] += 1
    else:
        p.add(i)
        a.append(i)
        b.append(1)
print(max(a))