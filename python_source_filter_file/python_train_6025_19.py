n,l=map(int,input().split())
a=list(map(int, input().split()))
for i in range(n-1):
  if a[i]+a[i+1]>=L:
    print("Possible")
    for j in range(i):print(j+1)
    for j in range(n-1,i,-1):print(i)
    exit()
print("Impossible")