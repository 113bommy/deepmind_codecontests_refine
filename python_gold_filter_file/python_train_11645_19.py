N,A,B=map(int,input().split())
if B<A or (N==1 and A!=B):
    print(0)
else:
    print((B-A)*(N-2)+1)