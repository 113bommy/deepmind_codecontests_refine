n=int(input())
a=[2,1]
for i in range(84):
    a.append(a[i]+a[i+1])
print(a[n])