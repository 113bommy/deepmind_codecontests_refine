n=int(input())
for i in range(n):
    s,a,b,c=map(int,input().split())
    nb=s//c
    if (nb>=a):
        nb+=((nb//a)*b)
    print(nb)
