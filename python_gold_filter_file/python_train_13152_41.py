n,a,b,c=map(int,input().split())
z=[0]+[-10000000]*4001
for i in range(1,n+1):
    z[i]=max(z[i-a],z[i-b],z[i-c])+1
print(z[n])