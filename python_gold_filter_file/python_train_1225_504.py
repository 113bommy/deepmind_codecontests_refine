N,K=map(int,input().split())
A=list(map(int,input().split()))
A=sorted(A)
print(sum(A[:K]))