tc = int(input())
while tc!=0:
    tc -= 1
    a , b = map(int,input().split())
    if a - b>1:
        print("YES")
    else:
        print("NO")
    