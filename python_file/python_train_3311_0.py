R,G,B,N = map(int,input().split())

cnt = 0
for r in range(N//R+1):
    for g in range(N//G+1):
        if (N-R*r-G*g) % B == 0 and R*r+G*g <= N:
            cnt += 1
print(cnt)