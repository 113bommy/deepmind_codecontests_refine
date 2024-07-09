n=int(input())
c,s,f=[0]*(n-1),[0]*(n-1),[0]*(n-1)
for i in range(n-1):
  c[i],s[i],f[i]=map(int,input().split())
arr=[0]*n
for i in range(n-1):
  for j in range(i,n-1):
    l=s[j]
    if arr[i]>l:
      while arr[i]>l:
        l+=f[j]
    arr[i]=l
    arr[i]+=c[j]
  print(arr[i])
print(0)