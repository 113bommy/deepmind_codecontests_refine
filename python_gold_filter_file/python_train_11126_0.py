d={}
for _ in[0]*int(input()):
 a,v=map(int,input().split())
 d.setdefault(v,[])
 d[v]+=[a]
m=max(d)
print(min(d[m]),m)
