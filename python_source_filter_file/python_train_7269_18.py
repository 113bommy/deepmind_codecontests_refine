N,Y= map(int,input().split())
for i in range(N):
    for j in range(N-i):
        if 10000*i + 5000*j + 1000*(N-i-j) == Y:
            print(i,j,N-i-j)
            exit()


print(-1,-1,-1)