t=int(input())
for i in range(t):
    n=int(input())
    l=[]
    for i in range(1,n+1):
        l.append(1000-i)
    print(*l)