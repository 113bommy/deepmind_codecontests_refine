n,m,k = map(int, input().split())

for h in range(n+1):
    for w in range(m+1):
        c = h*(n-w) + w*(m-h)
        if c==k:
            print("Yes")
            exit()
print("No")