import sys
sys.setrecursionlimit(10**7)
INF = 10 ** 18
MOD = 10 ** 9 + 7
def YesNo(x): return 'Yes' if x else 'No'
def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LI_(): return [int(x) - 1 for x in sys.stdin.readline().split()]
def LF(): return [float(x) for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def II(): return int(sys.stdin.readline())
def SI(): return input()

def get(n, rates):
    rates.sort()
    r0, a0, b0 = rates[0]
    r1, a1, b1 = rates[1]
    r2, a2, b2 = rates[2]
    if r0 >= 1:
        return n
    if r1 >= 1 or a0 == a1 == a2 or r0 == r1 == r2:
        return (n % a0) + (n // a0) * b0
    if r2 >= 1 or r1 == r2 or a1 == a2 or r0 == r1 or a0 == a1 or a0 == a2:
        if r0 == r1 or a0 == a1:
            r1, a1, b1 = r2, a2, b2
        ret = n
        for m0 in range(n // a0 + 1):
            rem = n - m0 * a0
            d = rem % a1
            tmp = d + m0 * b0 + (rem // a1) * b1
            ret = max(ret, tmp)
        return ret
    ret = n
    for m0 in range(n // a0 + 1):
        d0 = m0 * b0
        rem = n - m0 * a0
        for m1 in range(rem // a1 + 1):
            n2 = rem - m1 * a1
            d = n2 % a2
            tmp = d + d0 + m1 * b1 + (n2 // a2) * b2
            ret = max(ret, tmp)
    return ret

def main():
    N = II()
    ga, sa, ba = LI()
    gb, sb, bb = LI()
    rates = [[ga / gb, ga, gb], [sa / sb, sa, sb], [ba / bb, ba, bb]]
    rates2 = [[gb / ga, gb, ga], [sb / sa, sb, sa], [bb / ba, bb, ba]]
    ans = N
    ans = get(ans, rates)
    ans = get(ans, rates2)
    return ans

print(main())