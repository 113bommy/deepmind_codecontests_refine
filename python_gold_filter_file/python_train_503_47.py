n,a=map(int,input().split())
x=[0]+[i-a for i in map(int,input().split())]
d={}
def f(i):
    if i==n+1:
        return {0:1}
    if i in d:
        return d[i]
    d[i]={}
    for j in range(i+1,n+2):
        for k,v in f(j).items():
            d[i].setdefault(x[i]+k,0)
            d[i][x[i]+k]+=v
    return d[i]
print(f(0)[0]-1)