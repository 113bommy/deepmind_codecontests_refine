

t=int(input())
for i in range(t):
    a,k=map(int,input().split())
    count=0
    for j in range(k-1):
        a=str(a)
        if(min(str(a))!="0"):
            a=int(a)+int(min(str(a)))*int(max(str(a)))
        else:
            count=1
            break
    if(count==1):
        print(int(a)*(k-j))
    else:
        print(a)
        
        