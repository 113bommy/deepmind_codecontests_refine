s=[]
x=int(input())
l=list(map(int, input().split()))
for i in range(1,(len(l))):
    res=(l.index(i))+1
    s.append(res)
print(s)