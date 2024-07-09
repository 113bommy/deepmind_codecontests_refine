h, w, k = map(int, input().split())
s = [list(map(int, list(input()))) for _ in range(h)]
result = []
if h*w<=k:
    result.append(0)
else:
    for i in range(2**(h-1)):
        checker, num = 0, i
        while num > 0:
            checker += num%2
            num >>= 1
        x = 0
        c = [0 for _ in range(checker+1)]

        for j in range(w):
            num = i
            p = 0
            nex = [0 for _ in range(checker+1)]
            for m in range(h):
                nex[p] += s[m][j]
                p += num%2
                num = num >> 1          
            if max(nex)>k:
                x = 10**5
                break

            if all(nex[m]+c[m] <= k for m in range(checker+1)):
                c = [c[I]+nex[I] for I in range(checker+1)]
            else:
                x += 1
                c = nex
        result.append(checker+x)
print(min(result))