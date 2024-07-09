def solve():
    Sss = [input().rstrip() for _ in range(3)]

    Sss.sort(key=len, reverse=True)
    As, Bs, Cs = Sss
    lenA, lenB, lenC = len(As), len(Bs), len(Cs)

    def check(Ss, Ts):
        for S, T in zip(Ss, Ts):
            if not (S == T or S == '?' or T == '?'):
                return 0
        return 1

    def getISOKs(Ss, Ts):
        lenS, lenT = len(Ss), len(Ts)
        isOKs = [0] * (lenS+lenT+1)
        for iT in range(-lenT, 0):
            isOKs[iT] = check(Ss[:lenT+iT], Ts[-iT:])
        for iT in range(0, lenS-lenT+1):
            isOKs[iT] = check(Ss[iT:lenT+iT], Ts)
        for iT in range(lenS-lenT+1, lenS+1):
            isOKs[iT] = check(Ss[iT:], Ts[:lenS-iT])
        return isOKs

    isOKABs = getISOKs(As, Bs)
    isOKACs = getISOKs(As, Cs)
    isOKBCs = getISOKs(Bs, Cs)
    isOKBCs = isOKBCs[:lenB+1] + [1]*(lenA+lenB+lenC) + isOKBCs[lenB+1:]

    ans = lenA + lenB + lenC
    for iB in range(-lenB, lenA+1):
        if not isOKABs[iB]: continue
        for iC in range(-lenC, lenA+1):
            if isOKACs[iC] and isOKBCs[iC-iB]:
                L = max(lenA, iB+lenB, iC+lenC) - min(0, iB, iC)
                ans = min(ans, L)
    for iB in range(-lenB, lenA+1):
        if not isOKABs[iB]: continue
        for iC in range(-lenB-lenC, -lenC+1):
            if isOKBCs[iC-iB]:
                L = max(lenA, iB+lenB, iC+lenC) - min(0, iB, iC)
                ans = min(ans, L)
        for iC in range(lenA, lenA+lenB+1):
            if isOKBCs[iC-iB]:
                L = max(lenA, iB+lenB, iC+lenC) - min(0, iB, iC)
                ans = min(ans, L)
    for iC in range(-lenC, lenA+1):
        if not isOKACs[iC]: continue
        for iB in range(-lenB-lenC, -lenB+1):
            if isOKBCs[iC-iB]:
                L = max(lenA, iB+lenB, iC+lenC) - min(0, iB, iC)
                ans = min(ans, L)
        for iB in range(lenA, lenA+lenB+1):
            if isOKBCs[iC-iB]:
                L = max(lenA, iB+lenB, iC+lenC) - min(0, iB, iC)
                ans = min(ans, L)

    print(ans)


solve()
