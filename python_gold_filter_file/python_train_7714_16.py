l,r=map(int,input().split())
if(r-l<1):
    print("NO")
else:
    i=l
    print("YES")
    while(i<r):
        print(str(i)+" "+str(i+1))
        i+=2