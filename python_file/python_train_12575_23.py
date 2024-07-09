n=int(input())
s=input()
a=[[0]*n for i in range(n)]
buf=0
for i in range(n):
    for j in range(i+1,n):
        if i==0:
            if s[i]==s[j]:
                a[i][j]=1
            continue
        if s[i]==s[j]:
            a[i][j]=min(j-i,a[i-1][j-1]+1)
            buf=max(buf,a[i][j])
print(buf)