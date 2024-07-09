t=int(input())
for _ in range(t):
    n=int(input())
    a=input()
    b=input()
    count = [[0 for i in range(20)] for j in range(20)]
    ok=True
    for i in range(n):
        count[ord(a[i])-ord('a')][ord(b[i])-ord('a')]  += 1
        if ord(a[i])>ord(b[i]):
            ok=False
    if ok:
        ans = 0 
        for i in range(20):
            mini = 20
            for j in range(i+1,20):
                if count[i][j] > 0:
                    mini = min(mini,j)
            if mini < 20:
                ans += 1
                for j in range(mini+1,20):
                    if count[i][j] > 0:
                        count[mini][j] += 1
                
                
        print(ans)
    else:
        print(-1)