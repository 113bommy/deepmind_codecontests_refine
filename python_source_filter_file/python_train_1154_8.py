n,m=map(int,input().split())
l=list(map(int,input().split()))
pref=0
page=0
for i in l:
    pref+=i
    temp=pref//5
    print(temp-page,end=' ')
    page=temp