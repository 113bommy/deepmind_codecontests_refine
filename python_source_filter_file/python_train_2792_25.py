n, m, d = map(int,input().split())
if d > 1:
    print(2*(n-d)*(m-1) / (n**2))
else:
    print((m-1) / n)