n = int(input())
a = [list(map(int, input().split())) for _ in range(n)]

length = 0
for i in range(n) :
    for j in range(n):
        route = 10000000000
        for k in range(n):
            if k == i or k == j : continue
            route = min(route, a[i][k] + a[k][j] ) #< a[i][j]
            if route < a[i][j]:
                print(-1)
                exit() 
        if route > a[i][j] :
            length +=  a[i][j]
print(int(length/2))