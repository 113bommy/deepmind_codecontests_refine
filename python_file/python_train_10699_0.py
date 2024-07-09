T = int(input())

for _ in [0]*T:
    N = int(input())
    *A, = map(int,input().split())
    S = input()

    B = []
    ans = 0
    for s,a in zip(S[::-1],A[::-1]):
        if s=="0":
            B.append(a)
        else:
            # check
            C = B[:]
            for i in range(64):
                for b in C:
                    if (b >> i) & 1 == 1: break
                else:
                    continue
                if (a >> i) & 1 == 1: a ^= b
                for j,c in enumerate(C):
                    if (c >> i) & 1 == 1: C[j] ^= b
            if a!=0:
                ans = 1
                break
    print(ans)