a,b,c,d=map(int,input().split())
x=max(d+1,c)
ans=[]
for i in range(x,a+1) :
    for j in range(d,min(i,b+1)) :
        ans.append(str(i)+" "+str(j))
print(len(ans))
print("\n".join(ans))
