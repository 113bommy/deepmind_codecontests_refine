n,a,b=map(int,input().split())
w=list(map(int,input().split()))
w=[((x*a)%b)//a for x in w]
print(" ".join(map(str,w)))
