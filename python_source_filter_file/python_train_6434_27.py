n,m = map(int,input().split())
s = 0
t = n
for i in range(m):
    l,r = map(int,input().split())
    s = max(s,l)
    t = min(t,r)
print(int(t-s+1))
