n,k=map(int,input().split())
a=list(map(int,input().split()))
cost=[0]
for i in range(1, n):
  cost+=[min([cost[-j] + abs(a[i-j] - a[i]) for j in range(1,min(i,k)+1)])]
print(cost[-1])