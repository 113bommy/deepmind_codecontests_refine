for i in range(int(input())):
    n=int(input())
    l=list(map(int,input().split()))
    x=sum(l)%n
    print(x*(n-x))
	 	