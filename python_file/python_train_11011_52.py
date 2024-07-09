n,k = map(int,input().split())
a = list(map(int,input().split()))

for _ in range(k):
    r = [0]*(n+1)
    for i in range(n):
        r[max(i-a[i],0)] += 1
        r[min(i+a[i]+1,n)] -= 1
    for i in range(n-1):
        r[i+1] += r[i]
    a = r
    if a.count(n)==n:
        break
print(*a[:-1])
