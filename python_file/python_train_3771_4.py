N=int(input())
L=input()
S="0"
prev=L[0]
last=-1
for i in range(1,N):
    if L[i]<prev:
        S+="1"
        if last!=-1:
            if L[i]<last:
                print("NO")
                exit(0)
        last=L[i]
    else:
        S+="0"
        prev=L[i]
print("YES")
print(S)