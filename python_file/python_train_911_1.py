import sys
from collections import deque

readline = sys.stdin.readline
readall = sys.stdin.read
ns = lambda: readline().rstrip()
ni = lambda: int(readline().rstrip())
nm = lambda: map(int, readline().split())
nl = lambda: list(map(int, readline().split()))
prn = lambda x: print(*x, sep='\n')

def solve():
    n = ni()
    p = nl()
    diag = [-1, 1, n, -n]
    st = [1]*(n+2)**2
    gr = [0]*(n+2)**2
    ans = 0
    for i in range(n):
        for j in range(n):
            gr[i*n + j + n + 1] = min(min(i, j), n-1-max(i, j))
    for v in p:
        v += n
        ans += gr[v]
        st[v] = 0
        c = gr[v]
        for dv in diag:
            nv = v + dv
            c = min(c, gr[nv] + st[nv])
        gr[v]= c
        q = deque()
        q.append(v)
        while q:
            v = q.popleft()
            for dv in diag:
                nv = v + dv
                if gr[nv] > gr[v] + st[v]:
                    gr[nv] = gr[v] + st[v]
                    if st[v]:
                        q.append(nv)
                    else:
                        q.appendleft(nv)
    print(ans)
    return

if __name__ == '__main__':
    solve()
