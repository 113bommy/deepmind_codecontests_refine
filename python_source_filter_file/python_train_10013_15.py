b=int(input())
g=int(input())
n=int(input())
cnt=0
for i in range(b):
    for j in range(g):
        if(i+j==n):
            cnt+=1
print(cnt)            