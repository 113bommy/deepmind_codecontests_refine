n,x,y = map(int,input().split())
a = list(map(int,input().split()))
for i in range(n):
    t = True
    for j in range(max(0, i-x),min(n,i+y+1)):
        if i !=j and a[j] < a[i]:
            t = False
            break
    if t:
        print(i+1)
        exit()