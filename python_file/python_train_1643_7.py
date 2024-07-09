n=int(input())
x=input()
cntm=0
cntp=0
fn=0
xi=[0]*n
ans=[0]*n
for i in range(n):
    if x[i]=="1":
        fn+=1
for i in reversed(range(n)):
    if x[i]=="1":
        cntp+=pow(2,n-i-1,fn+1)
        cntp%=fn+1
        if fn>1:
            cntm+=pow(2,n-i-1,fn-1)
            cntm%=fn-1
for i in reversed(range(n)):
    if x[i]=="1":
        if fn>1:
            xi[i]=(cntm-pow(2,n-i-1,fn-1))%(fn-1)
            ans[i]+=1
    else:
        xi[i]=(cntp+pow(2,n-i-1,fn+1))%(fn+1)
        ans[i]+=1
#print(xi)
for i in range(n):
    num=xi[i]
    while num>0:
        cnt=0
        for j in range(31):
            if (num>>j)&1:
                cnt+=1
        num%=cnt
        ans[i]+=1
    print(ans[i])