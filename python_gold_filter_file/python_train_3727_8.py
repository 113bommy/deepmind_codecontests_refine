n,*t=map(int,open(0).read().split());A=t[:n];c=B=t[n:];r=0
while c:
 c=0
 for i in range(n):b=B[~-i%n]+B[-~i%n];t=(A[i]<B[i]>b)*(B[i]-A[i])//b;c+=t;B[i]-=t*b
 r+=c
print([-1,r][A==B])