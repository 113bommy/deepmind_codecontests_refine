n,k=map(int,input().split())
I=list(map(int,input().split()))
for i in range(k+1,n):
    if I[i-k]<I[i]:
        print("Yes")
    else:
        print("No")
    
