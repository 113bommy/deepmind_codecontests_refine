n = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

res = []
# 0 = A , 1 = B
for bit in range(2 ** n):
    if str(bin(bit)).count('1') % 2 == 1:
        continue

    odds = []
    evens = []
    for i in range(n):
        if (bit >> i) & 1:
            card = B[i]
            check = (i + 1) % 2

        else:
            card = A[i]
            check = i % 2

        if check == 1:
            odds.append([card, i+1])
        else:
            evens.append([card, i+1])

    if 0 <= len(evens) - len(odds) <= 1:
        odds.sort(reverse=True)
        evens.sort(reverse=True)
        now = 0
        pattern = []
        for _ in range(len(evens)):
            num1, idx1 = evens.pop()

            if now <= num1:
                now = num1
                pattern.append(idx1)
                if odds:
                    num2, idx2 = odds.pop()
                    if now <= num2:
                        now = num2
                        pattern.append(idx2)
                    else:
                        break

            else:
                break
        else:
            res.append(pattern)


if not res:
    print(-1)
    exit()

ans = []
for pattern in res:
    count = 0
    for i in range(n-1):
        num = pattern[i]
        check = pattern[i+1:]
        for t in check:
            if t < num:
                count += 1

    ans.append(count)

print(min(ans))