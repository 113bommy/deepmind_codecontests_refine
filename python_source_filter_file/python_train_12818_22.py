R=lambda:map(int,input().split())
n,x,y=R()
print(((sum(u<=y for u in R())+1)//2,n)[x>y])