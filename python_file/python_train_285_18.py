t = int(input())
ans = []

for tt in range(t):
    n = int(input())

    redk = {}
    bluek = {}
    asum = 0
    for i in range(n):
        k,l,r = list(map(int,input().split()))
        asum += min(l,r)
        if l >= r:
            if k in redk:
                redk[k].append(l-r)
            else:
                redk[k] = [l-r]
        else:
            if k in bluek:
                bluek[k].append(r-l)
            else:
                bluek[k] = [r-l]
    reds = []
    for i in range(1,n+1):
        if i in redk:
            reds += redk[i]
        while len(reds) > i:
            reds.remove(min(reds))
    blues = []
    for i in range(n,0,-1):
        if i in bluek:
            blues += bluek[i]
        while len(blues) >= n + 1 - i:
            blues.remove(min(blues))
    ans.append(asum + sum(reds) + sum(blues))

for i in range(len(ans)):
    print(ans[i])