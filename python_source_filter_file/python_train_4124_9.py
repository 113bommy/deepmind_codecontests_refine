def unimodal(a, lst):
    i = 1
    for i in range(i, a):
        if not (lst[i - 1] < lst[i]):
            break
    else:
        return "NO"

    for i in range(i, a):
        if not (lst[i - 1] == lst[i]):
            break
    else:
        return "NO"

    for i in range(i, a):
        if not (lst[i - 1] > lst[i]):
            return "NO"
    else:
        return "NO"

if __name__ == '__main__':
    a, lst = int(input()), input().split()
    lst = [int(ch) for ch in lst]
    print(unimodal(a, lst))
