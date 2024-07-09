n=int(input())
a=list(map(int,input().split()))
ans=0
for i in a:
    ans^=i
k=~ans
for i in range(n):
    a[i]&=k
rank=0
# 掃き出し法
for i in range(59,-1,-1):
    for j in range(rank,n):
        if a[j]>>i&1:
            break
    if j==n:
        continue
    if j>rank:
        # a[rank]のi番目のbitを1にするswapでもいい
        a[rank]^=a[j]
    for j in range(rank+1,n):
        a[j]=min(a[j],a[j]^a[rank])
    res=0
    rank+=1
for i in a:
    res=max(res,res^i)
print(ans+2*res)