n,k=map(int,input().split())
print(max(min(n-(k+1)//2+1,k//2),0))