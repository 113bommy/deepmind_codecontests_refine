ins = lambda x:map(x,input().split())
n,m = ins(int)
x = list(ins(int))
x = list((i-1)//m for i in x)
print(n - x[::-1].index(max(x)))