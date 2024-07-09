n,m = map(int,input().split())
a = [int(x) for x in input().split()]
b = [int(x) for x in input().split()]

mins = [0]*n
for j in range(n):
    mins[j] = min([a[j] & i for i in b])

lb = max(mins)

for j in range(n):
    lb = min([lb | (a[j] & i) for i in b])

print(lb)