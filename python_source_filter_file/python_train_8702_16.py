R=lambda:list(map(int,input().split()))
a,b,c,d=R()
e,f=R()
print('Yes'if abs(a-c)%e==0 and abs(b-d)%f==0 and abs(a-c)/e==abs(b-d)/f else'No')
