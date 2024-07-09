def add(i,x):
    global BIT
    i+=1
    while i<=n:
        BIT[i] += x
        i += i&(-i)
        
def bitsum(i):
    x = 0
    i+=1
    while i>0:
        x += BIT[i]
        i -= i&(-i)
    return x

def sums(l,r):
    return bitsum(r-1)-bitsum(l-1)

n,q = map(int,input().split())
c = list(map(int,input().split()))
pi = [-1]*(n+1)
ps = [[] for _ in range(n)]
qs = [[] for _ in range(n)]
for i in range(n):
    l = pi[c[i]]
    if l!=-1:
        ps[l].append(i)
    pi[c[i]] = i
for i in range(q):
    l,r = map(int,input().split())
    l,r = l-1,r-1
    qs[l].append((r,i))
BIT = [0]*(n+1)
ans = [None]*q
for x in range(n-1,-1,-1):
    for y in ps[x]:
        add(y,1)
    for r,i in qs[x]:
        ans[i] = r-x+1-bitsum(r)

for i in ans:
    print(i)