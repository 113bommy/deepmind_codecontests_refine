# 解説の写経

def solve_panasonic2020_e():
    def unmatched(c1: str, c2: str) -> bool:
        """c1,c2がマッチしない"""
        return not (c1 == '?' or c2 == '?' or c1 == c2)

    A = input()
    B = input()
    C = input()

    MX = max(map(len, [A, B, C]))

    # 相対位置ごとの文字列マッチングの可否を調べる
    # ab/ac/bc[index差]:=その相対位置でマッチしないときTrue
    # [-MX,MX]
    # + : 左文字より右文字が右にある, a->b
    # - : 右文字より左文字が右にある, b->a
    ab = [False] * (MX * 4 + 1)
    ac = [False] * (MX * 4 + 1)
    bc = [False] * (MX * 4 + 1)

    for i, a in enumerate(A):
        for j, b in enumerate(B):
            ab[i - j] |= unmatched(a, b)

    for i, a in enumerate(A):
        for j, c in enumerate(C):
            ac[i - j] |= unmatched(a, c)

    for i, b in enumerate(B):
        for j, c in enumerate(C):
            bc[i - j] |= unmatched(b, c)

    # Aに対するB,Cの相対位置MX**2で全探索
    ans = sum(map(len, [A, B, C]))
    for i in range(-MX * 2, MX * 2 + 1):  # ACBのようにAB間にMX分空くこともあって、幅2MX
        if ab[i]: continue
        for j in range(-MX * 2, MX * 2 + 1):  # ABCのようにAC間にMX分空くこともあって、幅2MX
            if ac[j]: continue
            if bc[j - i]: continue
            # 添え字で混乱するが
            # ab[i-j]で
            # 添え字i-jは(bの開始)-(aの開始)を意味したことから
            # (i-j>0でa->bの配置から)
            # 今回i,jは(aの開始)を基準にした(b,cの開始位置)で
            # bcの添え字は(cの開始)-(bの開始)なのでj-i

            # [L,R)
            L = min(0, i, j)
            R = max(len(A), i + len(B), j + len(C))
            ans = min(ans, R - L)

    print(ans)
    return


if __name__ == '__main__':
    solve_panasonic2020_e()

# N**3は通らない
# N**2の方針=2本の文字列の捜査
