a,b,c = map(int,input().split())
print(min(a+b+c,a+c+c+a,b+c+c+a,a+a+b+b))