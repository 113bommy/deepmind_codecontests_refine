t=int(input())
for _ in range(t):
    n,r=map(int,input().split())
    if n<r:
        print((n*(n-1))//2 + 1)
    else:
        print((r*(r+1))//2)