

player_one = 'Ciel'
player_two = 'Hanako'


c100, c10 = map(int, input().split())


while True:
    if 100 * c100 + 10 * c10 >= 220 and c10 >= 2:
        tmp = max([2, c100])
        c100 -= tmp
        c10 -= (220 - 100 * tmp) // 10
    else:
        print(player_two)
        break

    if 100 * c100 + 10 * c10 >= 220 and c10 >= 2:
        if c10 >= 22:
            c10 -= 22
        elif c10 >= 12:
            c10 -= 12
            c100 -= 1
        else:
            c10 -= 2
            c100 -= 2
    else:
        print(player_one)
        break







