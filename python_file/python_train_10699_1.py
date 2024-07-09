def main():
    t = int(input())
    for _ in range(t):
        nn, aa, s, r, mm = int(input()), list(map(int, input().split())), input(), 0, []
        for ii in range(nn-1, -1, -1):
            ai = aa[ii]
            mm += [[(ai >> jj) & 1 for jj in range(64)]]
            n, i, j = r+1, 0, 0
            while i < n and j < 64:
                if mm[i][j] == 1 and mm[n-1][j] == 0:
                    i += 1
                    j += 1
                    continue
                if mm[i][j] == 0:
                    if mm[n-1][j] != 0:
                        for l in range(j, 64):
                            mm[i][l] ^= mm[n-1][l]
                    else:
                        j += 1
                        continue
                M2 = mm[i]
                for k in range(i+1, n):
                    M3 = mm[k][j]
                    mm[k][j] = 0
                    for l in range(j+1, 64):
                        mm[k][l] ^= M3*M2[l]
                i += 1
                j += 1
    
            if s[ii] == "0":
                if i > r:
                    r += 1
                else:
                    mm.pop()
            else:
                mm.pop()
                if i > r:
                    print(1)
                    break
        else:
            print(0)


main()
