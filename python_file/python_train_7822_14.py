n = int(input())
a = list(map(int,input().split()))
s = ""
l = 0
cur=0
r = n-1
while l<=r and max(a[l],a[r])>cur:
    if a[l]>cur>a[r] or a[r]>=a[l]>cur:
        s+="L"
        cur=a[l]
        l+=1
    else:
        s+="R"
        cur=a[r]
        r-=1
print (len(s),s)
