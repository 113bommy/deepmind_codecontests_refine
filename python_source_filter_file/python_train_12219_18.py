'''
Amirhossein Alimirzaei
Telegram : @HajLorenzo
Instagram : amirhossein_alimirzaei
University of Bojnourd
'''

input()
tmp=list(map(int,input().split()))
C=[0,0,0]
i=0
for _ in tmp:
    C[i]+=_
    i+=1
    if i==2:
        i=0
print(["chest","biceps","back"][C.index(max(C))])

