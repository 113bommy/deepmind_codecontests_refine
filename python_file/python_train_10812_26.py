s=input()
K=int(input())
ans=''
for c in s:
    if c!='a' and ord('z')+1-ord(c)<=K:
        ans+='a'
        K-=ord('z')+1-ord(c)
    else:
        ans+=c
if K>0:
    ans=ans[:-1]+chr(ord(ans[-1])+K%26)

print(ans)