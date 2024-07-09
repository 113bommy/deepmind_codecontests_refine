n=int(input())
a=list(map(int,input().split()))
num1,num2,num3=0,0,0
for i in range(n):
    if a[i]==1:
        num1+=1
    elif a[i]==2:
        num2+=1
    else:
        num3+=1
dp=[[[-1.0 for k in range(n+1)] for i in range(n+1)] for j in range(n+1)]
def f(n1,n2,n3):
    if dp[n1][n2][n3]>=0.0:
        return dp[n1][n2][n3]
    if n1==n2==n3==0:
        return 0.0
    ret=n
    if n1>0:
        ret+=f(n1-1,n2,n3)*n1
    if n2>0:
        ret+=f(n1+1,n2-1,n3)*n2
    if n3>0:
        ret+=f(n1,n2+1,n3-1)*n3
    ret*=1.0/(n1+n2+n3)
    dp[n1][n2][n3]=ret
    return dp[n1][n2][n3]
print(f(num1,num2,num3))
