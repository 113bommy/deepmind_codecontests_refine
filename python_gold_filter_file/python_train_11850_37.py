n,m = map(int,input().split())

a = (m//n)

for i in range(a, 0, -1):
    if m%i == 0:
        print(i)
        break