x=input().split()
n=int(x[0])
k=int(x[1])
for i in range(k):
    if n%10==0:
        n=n/10
    else:
        n=n-1
print(n)
    
