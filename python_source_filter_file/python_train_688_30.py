a=int(input())
k=1
z=1
u=''
for i in range(1,a):
    if i==z:
        z=k+z
        k=z-k
        u=u+"0"
    else:
        u=u+"o"
print(u)        
