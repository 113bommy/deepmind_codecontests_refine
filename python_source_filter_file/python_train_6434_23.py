N ,M  = map(int,input().split())
L = 0
R = N
for i in range(M):
    a,b = map(int,input().split())
    L = max(L,a)
    R = min(R,b)
print(R-L+1)