n=int(input())

pdat=[]
mdat=[]

for i in range(n):
    s=input()
    
    mini=0
    now=0
    for q in range(len(s)):
        if s[q]=="(":
            now+=1
        else:
            now-=1
            mini=(min(mini,now))
    if now>=0:
        pdat.append((now,mini,mini-now))
    else:
        mdat.append((now,mini,mini-now))

pdat.sort(key=lambda x:-x[1])
mdat.sort(key=lambda x:x[2])

now=0
for d in pdat+mdat:
    if now+d[1]<0:
        print("No")
        break
    now+=d[0]
else:
    if now==0:
        print("Yes")
    else:
        print("No")