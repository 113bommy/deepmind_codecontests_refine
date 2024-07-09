t = int(input(''))
for i in range(t):
    n = int(input(''))
    a = list(map(int,input('').split(' ')))
    pref = [[0]*(n+1) for i in range(26)]
    a = [0]+a
    for c in range(26):
        for i in range(1,n+1):
            if a[i] == (c+1):
                pref[c][i] = pref[c][i-1]+1
            else:
                pref[c][i] = pref[c][i-1]
    ans = 0
    for aa in range(26):
        l = 1
        r = n
        cnt = 0
        for c in range(26):
            ans = max(ans,2*cnt + (pref[c][n]))
        while (l < r):
            while (l <= n and a[l] != (aa+1)):
                l+=1
            if (r <= l):
                break
            while (r >= 1 and a[r] != (aa+1)):
                r-=1
            if (r <= l):
                break
            cnt += 1
            for c in range(26):
                ans = max(ans,2*cnt + (pref[c][r-1]-pref[c][l]))
            l+=1
            r-=1
    print(ans)
