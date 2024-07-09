from collections import defaultdict
n = int(input())
a = [[]]
for _ in range(n):
    tmp = [int(x) for x in input().split()]
    a.append(tmp[::-1])

p = [i for i in range(1, n+1)]
c = defaultdict(int)
done = 0
for d in range(1, n*(n-1)//2+1):
    np = []
    for pp in p:
        if len(a[pp]) == 0:
            continue
        x = a[pp].pop()
        l = min(x, pp)
        r = max(x, pp)
        c[l, r] += 1
        if c[l, r] == 2:
            np.append(l)
            np.append(r)
            done += 1
    if done == (n*(n-1)//2):
        print(d)
        exit()
    if len(np) == 0:
        print(-1)
        exit()
    p = np