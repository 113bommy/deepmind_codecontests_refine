N,M=map(int,input().split())
box=[[] for i in range(N)]
for i in range(M):
    a,b=map(int,input().split())
    box[a-1].append(b-1)
    box[b-1].append(a-1)
ans=[None]*(N)
ans[0]=0
que=[0]
while len(que)>0:
    index=que.pop(0)
    for x in box[index]:
        if ans[x]==None:
            ans[x]=index+1
            que.append(x)
print("Yes")
for i in range(1,N):
    print(ans[i])
