a,b,c=map(int,input().split())
r=0
while (b/a)*100<c:
 b+=1
 r+=1
print(r)