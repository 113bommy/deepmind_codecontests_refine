''' K for the Price of One (Easy Version)
'''

T = int(input())

for test in range(T):
    N, P, K = list(map(int, input().split()))
    prices = list(map(int, input().split()))
    prices.sort()

    goodsmax = 0
    for start in range(K):
        Pcpy = P
        index = start
        goods = 0
        while index < N:
            # print(index)
            if prices[index] <= Pcpy:
                Pcpy -= prices[index]
                # print(start, K, index + 1)
                goods += min(K, index + 1)
                index += K
            else: break
        index -= (K - 1)
        while index < N:
            if prices[index] <= Pcpy:
                goods += 1
                index += 1
            else: break
        goodsmax = max(goods, goodsmax)
    print(goodsmax)