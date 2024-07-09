t = int(input())
for _ in range(t):
    n = int(input())
    a = [(int(x), i) for i, x in enumerate(input().split())]

    a.sort()

    # b = [(x, i, sorted_i) for sorted_i, (x, i) in enumerate(a)]
    # b.sort(key=lambda x: x[1])

    # print("=======")
    # print(a)

    mx = 0
    curl = 0
    prev = -1000
    for x, i in a:
        if i > prev:
            curl += 1
        else:
            curl = 1
        prev = i

        if curl > mx:
            mx = curl

    print(n - mx)


