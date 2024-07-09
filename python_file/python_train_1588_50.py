from sys import stdin, stdout  
from math import tan
from math import pi
t=int(stdin.readline())
for _ in range(t):
    n=int(stdin.readline() )
    #arr=list(map(int, stdin.readline() .strip().split()))
    #a,b,c,d=(map(int, stdin.readline().strip().split()))
    #s=stdin.readline()
    #stdout.write(str(cp))
    #stdout.write("\n")
    print( 1/tan(pi/(n*2) ) )
