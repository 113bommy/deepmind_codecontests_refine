q=int(input())
for i in range(0,q):
    n=int(input())
    s=input()

    if(n==2 and s[0]>=s[1]):
        print("NO")
    else:
        print("YES")
        print(2)
        print(s[0]+' ' + s[1:])
