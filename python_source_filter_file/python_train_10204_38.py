n = int(input())
a = list(map(int, input().split()))
for  i in range(n):
    v  = a[i]
    j = i-1
    while a[j]>v and j>=0:
        a[j+1] = a[j]
        j -=1
    a[j] = v
    print(*a)
