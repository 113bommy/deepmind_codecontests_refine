t=int(input())
for _ in range(t):
    n,p,k=map(int,input().split())
    a=list(map(int,input().split()))
    a.sort()
    pre=0
    ans=0
    for i in range(min(k+1,n)):
        s=pre
        if(s>p):
            break
        count=i
        for j in range(i+k-1,len(a),k):
            if(s+a[j]>p):
                break
            else:
                s+=a[j]
                count=count+k 
        ans=max(ans,count)
        pre=pre+a[i]
    print(ans)