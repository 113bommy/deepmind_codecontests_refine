N,K=map(int,input().split())
M=N%K
print(min(M,K-M))