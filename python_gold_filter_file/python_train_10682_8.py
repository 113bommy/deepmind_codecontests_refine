n,k,t=map(int,input().split())
if t<k:
    print(t)
elif t>=k and t<=n:
    print(k)
else:
    print(k-(t-n))