import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**9)

def solve():
    INF = float('inf')

    idEle = -INF  # max
    def _binOpe(x, y):
        return x if x >= y else y  # max
    def makeSegTree(numEle):
        numPow2 = 2 ** (numEle-1).bit_length()
        data = [idEle] * (2*numPow2)
        return data, numPow2
    def setInit(As):
        for iST, A in enumerate(As, numPow2):
            data[iST] = A
        for iST in reversed(range(1, numPow2)):
            data[iST] = _binOpe(data[2*iST], data[2*iST+1])
    def _update1(iA, A):
        iST = iA + numPow2
        data[iST] = A  # set
    def update(iA, A):
        _update1(iA, A)
        iST = iA + numPow2
        while iST > 1:
            iST >>= 1
            data[iST] = _binOpe(data[2*iST], data[2*iST+1])
    def getValue(iSt, iEn):
        L = iSt + numPow2
        R = iEn + numPow2
        ans = idEle
        while L < R:
            if L & 1:
                ans = _binOpe(ans, data[L])
                L += 1
            if R & 1:
                R -= 1
                ans = _binOpe(ans, data[R])
            L >>= 1
            R >>= 1
        return ans


    N, K = map(int, input().split())
    As = [int(input()) for _ in range(N)]

    maxA = max(As)

    data, numPow2 = makeSegTree(maxA+1)
    setInit([0]*(maxA+1))

    for A in As:
        L, R = A-K, A+K
        if L < 0:
            L = 0
        if R > maxA:
            R = maxA
        v = getValue(L, R+1)
        update(A, v+1)

    ans = getValue(0, maxA+1)
    print(ans)


solve()
