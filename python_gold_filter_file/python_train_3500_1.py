n, k = list(map(int, input().split()))
a = list(map(int, input().split()))
if k == 1:
    print(min(a))
elif k == 2:
    print(max(a[0], a[n-1]))
else:
    print(max(a))
