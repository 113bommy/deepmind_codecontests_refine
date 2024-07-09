n,k=[int(i) for i in input().split()]
h=[int(i) for i in input().split()]
d=[0]*n
for i in range(1,n):
  d[i]=min([d[j] + abs(h[i]-h[j]) for j in range(max(i-k,0),i)])
print(d[n-1])