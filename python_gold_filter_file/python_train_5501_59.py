n,m,k = map(int,input().split())
for i in range(n+1):
    for j in range(m+1):
        if k==i*m+(n-2*i)*j:
            print('Yes')
            exit()
print('No')