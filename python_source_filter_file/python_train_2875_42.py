a,b=map(int,input().split())
if b==0:print(0,0);exit()
print(min(1,a-b),min(b+1,a-b))