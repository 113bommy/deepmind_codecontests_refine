# https://codeforces.com/problemset/problem/1042/B
nb_juices = int(input())
cABC = 300001
cAB = 300001
cAC = 300001
cBC = 300001
cA = 300001
cB = 300001
cC = 300001
for n in range(nb_juices):
    c, s = [x for x in input().split()]
    c = int(c)
    vA = s.count("A")
    vB = s.count("B")
    vC = s.count("C")
    if vA==1 and vB==1 and vC==1:
        if c<cABC:
            cABC=c
    if vA==1 and vB==1:
        if c<cAB:
            cAB=c
    if vA==1 and vC==1:
        if c<cAC:
            cAC=c
    if vB==1 and vC==1:
        if c<cBC:
            cBC=c
    if vA==1:
        if c<cA:
            cA=c
    if vB==1:
        if c<cB:
            cB=c
    if vC==1:
        if c<cC:
            cC=c
cout = min(cABC, cAB+cC, cAC+cB, cBC+cA, cA+cB+cC)
if cout == 300001:
    print(-1)
else:
    print(cout)
