n=int(input())
l=list(map(int,input().split()))
ls=[0]*400001
for i in range(n):
    ls[l[i]-i]+=l[i]
print(max(ls))
        
   