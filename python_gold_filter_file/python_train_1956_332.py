n,k=map(int,input().split())
if n>=k:n%=k
print(min(n,k-n))