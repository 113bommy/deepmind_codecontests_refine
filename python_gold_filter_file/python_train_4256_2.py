n = int(input())
a = list(map(int,input().split()))
a = sorted(a)
print(sum(a[::2]))