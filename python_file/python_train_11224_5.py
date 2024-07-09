def solve(aaa):
    l = 1
    r = 200000
    while l < r:
        m = (l + r) // 2
        if check(m, aaa):
            r = m
        else:
            l = m + 1
    return r


def check(d, aaa):
    if d == 1:
        return all(a1 < a2 for a1, a2 in zip(aaa, aaa[1:]))
    l = 0
    word = {}
    for a in aaa:
        if l >= a:
            if not carry(d, word, a):
                return False
            for i in list(word.keys()):
                if a < i:
                    del word[i]
        l = a
    return True


def carry(d, word, i):
    while i > 0:
        if i in word:
            if word[i] < d:
                word[i] += 1
                return True
            del word[i]
        else:
            word[i] = 2
            return True
        i -= 1
    return False


n = int(input())
aaa = list(map(int, input().split()))
print(solve(aaa))
