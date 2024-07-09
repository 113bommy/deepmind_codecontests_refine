N = int(input())
A = list(map(int,input().split()))

def is_ok(k):
    length = 0
    mem = {}
    for a in A:
        if a > length:
            length = a
            continue
        dels = []
        for b in mem.keys():
            if b > a:
                dels.append(b)
        while a > 0:
            if a in mem and mem[a] >= k-1:
                dels.append(a)
            else:
                break
            a -= 1
        if a in mem:
            mem[a] += 1
        else:
            mem[a] = 1
        if a == 0 or mem[a] >= k:
            return False
        length = a
        for b in dels:
            del mem[b]
    return True

ng = 0
ok = N
while ok-ng > 1:
    m = (ok+ng+1)//2
    if is_ok(m):
        ok = m
    else:
        ng = m
print(ok)