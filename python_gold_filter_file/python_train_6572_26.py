n=int(input())
s=[]
r=0
for i in range(n):
    s.append(input())
for i in range(1,n-1):
    for j in range(1,n-1):
        if s[i][j]==s[i-1][j-1]==s[i-1][j+1]==s[i+1][j-1]==s[i+1][j+1]=='X':
            r+=1
print(r)