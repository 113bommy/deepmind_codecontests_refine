def max_ten(s):
    if memo[s]!="e":
        return memo[s]
    ten = 0
    # 分けない場合の点数
    for ai, ar in enumerate(a[:-1]):
        if s >> ai & 1:
            ten += sum(ar[j] * (s >> j & 1) for j in range(1 + ai, n))
    # 分ける場合の点数
    bubun = (s - 1) & s
    while bubun > 0:
        kari = max_ten(bubun) + max_ten(bubun ^ s)
        if kari > ten:
            ten = kari
        bubun = (bubun - 1) & s
    memo[s] = ten
    return ten


n = int(input())
a = [list(map(int, input().split())) for _ in range(n)]
s = (1 << n) - 1
memo = ["e"] * (1 << n)
print(max_ten(s))
