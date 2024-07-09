n,k = map(int,input().split())
p = [i-1 for i in list(map(int,input().split()))]
c = list(map(int,input().split()))
ans = -float("inf")
for i in range(n):
    now = i
    cnt = [0]
    for j in range(n):
        nxt = p[now]
        cnt.append(cnt[j]+c[nxt])
        now = nxt
        if now == i:
            break
    m = len(cnt)-1
    if k <= m:
        s = max(cnt[1:(k+1)])
    elif cnt[-1] < 0:
        s = max(cnt[1:])
    else:
        t = k//m
        s = (t-1)*cnt[-1]+max(cnt[1:])
        s = max(s, t*cnt[-1]+max(cnt[:(k-t*m+1)]))
    ans = max(ans,s)
print(ans)