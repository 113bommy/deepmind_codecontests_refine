t=int(input())
for i in range(t):
    n = int(input())
    a=input().split(" ")
   
    a.sort(reverse=True,key=int)
    print (" ".join([k for k in a]))