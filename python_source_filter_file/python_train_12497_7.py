import sys
e=[list(map(int,e.split()))for e in sys.stdin]
n=e[0][0]+1
for c in e[:n]:print(*[sum(s*t for s,t in zip(c,l))for l in zip(*e[n:])])
