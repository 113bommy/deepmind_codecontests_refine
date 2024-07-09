def main():
    n, m = map(int, input().split())
    st = [list(map(int, input().split())) for _ in [0]*m]
    g = [[] for _ in [0]*n]
    [g[a-1].append(b-1) for a, b in st]
    toP = [0]*n
    toE = [0]*n
    fromE = [0]*n
    toP[0] = 1
    for i in range(n-1):
        p = toP[i]
        if p > 0:
            toE[i] /= toP[i]
        e = toE[i]
        l = len(g[i])
        for j in g[i]:
            toP[j] += p/l
            toE[j] += (e+1)*p/l
    for i in range(n-2, -1, -1):
        l = len(g[i])
        for j in g[i]:
            fromE[i] += (fromE[j]+1)/l
    allE = fromE[0]
    ans = fromE[0]
    for s, t in st:
        if g[s-1]:
            temp = allE
            l = len(g[s-1])
            if l < 2:
                continue
            p = toP[s-1]
            temp = allE
            for j in g[s-1]:
                temp -= p*(toE[s-1]+1+fromE[j])/l
                if j != t-1:
                    temp += p*(toE[s-1]+1+fromE[j])/(l-1)
            ans = min(temp, ans)
    print(ans)


main()