s=str(input())
f=["h","e","i","d","i"]
j=0
for i in s:
    if j==4:
        break
    if i ==f[j] :
        j+=1
if j==4:
    print("YES")
else:
    print("NO")