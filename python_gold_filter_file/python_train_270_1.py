n=int(input())
w=[]
for _ in range(n):
    w.append(int(input()))
s=3
for i in w:
    if i==s:
        print("NO")
        exit()
    s=6-s-i
    
print("YES")
    
    
    