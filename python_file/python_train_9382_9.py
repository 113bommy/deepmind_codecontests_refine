n = int(input())

a = list(map(int,input().split()))
c = 0
for i in range(n):
    if a[i] % 2 == 1:
        if i % 2 == 1:
            c = c - 1
        else:
            c = c + 1
if (n % 2 == 1 and (c == 0 or c == 1)) or (n % 2 == 0 and c == 0):
    print("YES")
else :
    print("NO")