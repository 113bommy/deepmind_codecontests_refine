(w,h)=map(int,input().split())
(u1,d1)=map(int,input().split())
(u2,d2)=map(int,input().split())
for i in range(h,-1,-1):
    w+=i
    if i ==d2:
        w=max(0,(w-u2))
    if i==d1:
        w=max(0,(w-u1))
print(w)
