n,k,x,y=(int(input()) for i in range(4))
print(n*x if n<=k else (k*x+(n-k)*y))