n=int(input())
nums=list(map(int,input().split()))
res=[]
left=0
right=n-1
cur=-1
for i in range(n):
    l=nums[left]
    r=nums[right]
    if l>cur and r>cur:
        if r>l:
            res.append('L')
            left+=1
            cur=l
        else:
            res.append('R')
            right-=1
            cur=r
    elif l>cur:
        res.append('L')
        left+=1
        cur=l
    elif r>cur:
        res.append('R')
        right-=1
        cur=r
    else:
        break
print(len(res))
for x in res:
    print(x,end='')
