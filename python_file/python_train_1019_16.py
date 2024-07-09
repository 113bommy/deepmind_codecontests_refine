n=int(input())
s=input()
t=s.count("#")
for i in s:
    if i=="#": t-=1
    else: t+=1
    t=min(t,s.count("#"))
print(t)