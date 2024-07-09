L,R=map(int,input().split())
R=min(R,L+4038)
ans=2020
for i in range(L,R+1):
    for j in range(L,R+1):
        if i!=j: ans=min(ans,(i*j)%2019)
print(ans)