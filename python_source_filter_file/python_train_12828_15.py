# cook your dish here
t=int(input())
for _ in range(t):
    n,x,y=map(int,input().split(" "))
    if x+y>n:
        print(x+y-n+1,n)
    else:
        m=n-x-y
        m+=1
        print(1,n-m)