def ext_euc(a, b):
    if b == 0:
        return 1, 0, a
    y, x, v = ext_euc(b, a % b)
    y -= (a // b) * x
    return x, y, v


def mod_inv(a, mod):
    x, _, _ = ext_euc(a, mod)
    return x % mod


def main():
    p = int(input())
    A = list(map(int, input().split()))
    # comb(p - 1, i)
    comb = [1] * p
    for i in range(1, p):
        v = comb[i - 1]
        v *= p - i
        v *= mod_inv(i, p)
        comb[i] = v % p
    b = [0] * p
    for k, a in enumerate(A):
        if a == 0:
            continue
        pw = [1] * p  # (- k)**(p - 1 - i)
        for i in range(1, p):
            pw[- (i + 1)] = (pw[- i] * (- k)) % p
        for i in range(p):
            if i == 0:
                b[i] += 1
            b[i] -= comb[i] * pw[i]
            b[i] %= p
    print(' '.join(map(str, b)))            


if __name__ == '__main__':
    main()