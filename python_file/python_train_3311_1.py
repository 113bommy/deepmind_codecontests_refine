R,G,B,N=map(int,input().split())
cnt=0
for i in range(N+1):
    for j in range(N+1):
        if i*R+j*G<=N and (N-(i*R+j*G))%B==0:
            cnt+=1
print(cnt)