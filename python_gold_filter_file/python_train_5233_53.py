t = int(input())

for i in range(t):
    a, b = map(int, input().split())
    
    if 2*a > b:
        print(-1, -1)
    else:
        print(a, 2 * a)