n=int(input())
a={}
for i in range(n):
    b=int(input())
    if b in a[b]:
        del a[b]
    else:
        a[b]=1

print(len(a))