N=int(input())
if N==0:
    print("Yes")
    exit()

P=[]
M=[]
for i in range(N):
    s=input()
    f=0
    m=0
    cnt=0
    for j in range(len(s)):
        if s[j]=="(":
            cnt+=1
        else:
            cnt-=1
            if cnt<m:
                m=cnt
    if cnt>=0:
        P.append([m,cnt])
    else:
        M.append([m-cnt,-cnt])
P.sort(reverse=True)
M.sort(reverse=True)
#print(P)
#print(M)
SUM=0
for i,j in P:
    SUM+=j
for i,j in M:
    SUM-=j
if SUM!=0:
    print("No")
    exit()

SUMP=0
for i,j in P:
    if SUMP>=(-i):
        SUMP+=j
    else:
        print("No")
        exit()
        
SUMM=0
for i,j in M:
    if SUMM>=(-i):
        SUMM+=j
    else:
        print("No")
        exit()
print("Yes")