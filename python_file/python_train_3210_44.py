a,b,k=map(int,input().split())
for i in range(a,b+1):
    if i not in range(a+k,b+1-k):
        print(i)
