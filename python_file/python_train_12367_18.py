def main():
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    ab = sorted([[a[i], b[i]] for i in range(n)],key=lambda x:x[1])
    num=131071

    m=num+n
    segtree=[10**9+1]*m
    for i in range(num,m):
        segtree[i] = ab[i - num][0]
    for i in range(num-1,-1,-1):
        j=2*i+1
        if j>=m:
            segtree[i]=10**9+1
        elif j+1>=m:
            segtree[i]=segtree[j]
        else:
            segtree[i] = min(segtree[j], segtree[j + 1])

    #探す
    def search(i, s):
        if i >= num:
            return i - num
        k = 2 * i + 1
        if k+2<=m:
            if segtree[k+1] <= s:
                return search(k+1, s)
        if 2*i+2<=m:
            if segtree[k] <= s:
                return search(k, s)
        return -1
    
    #更新
    def update_good(i, s):
        if segtree[i] > s:
            segtree[i] = s
            update_good((i - 1) // 2, s)
    
    def update_bad(i):
        k=(i - 1) // 2
        if i % 2 == 1:
            if m > i + 1:
                temp=min(segtree[i+1],segtree[i])
                if segtree[k]<temp:
                    segtree[k] = temp
                    update_bad(k)
            else:
                segtree[k] = segtree[i]
                update_bad(k)
        else:
            if i != 0:
                temp=min(segtree[i-1],segtree[i])
                if segtree[k]<temp:
                    segtree[k] = temp
                    update_bad(k)

    cnt = 0
    for i in range(n):
        a,b=ab[i][0],ab[i][1]
        if a > b:
            t = search(0, b)
            if t <= i:
                print("No")
                return 0
            update_good(num + i, a)
            segtree[num + t] = a
            update_bad(num + t)
            ab[i][0], ab[t][0] = ab[t][0], a
            cnt+=1
    if cnt <= n - 2:
        print("Yes")
    else:
        print("No")
    
main()