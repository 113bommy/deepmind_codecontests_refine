t = int(input())
while(t):
    n, m = map(int, input().split())
    if(n == 1 or m == 1):
        print("YES")
    elif(n == 2 or m == 2):
        print("YES")
    else:
        print("NO")
    t = t - 1