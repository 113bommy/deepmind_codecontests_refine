

global N,K
global ws

def check(max_p):
    track=0
    now=0
    for i in range (N):
        if(ws[i]>max_p):return False
        if(now+ws[i]>max_p):
            track+=1
            now=ws[i]
        else:
            now+=ws[i]
    if now>0:
        track+=1
    if(track>K):
        return False
    else:
        return True

N,K=map(int,input().split())

ans=0
now=0
ws=[]
for i in range(N):
    w=int(input())
    ws.append(w)

amin=0
amax=int(1E48)

while amin+1!=amax:
    amid=(amin+amax)//2
    if(check(amid)):
        amax=amid
    else:
        amin=amid
print(amax)
   