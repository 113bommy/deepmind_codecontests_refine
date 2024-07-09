N = int(input())
tm_pos = [list(map(int, input().split())) for i in range(N)]
for i in tm_pos:
    if i[0] < i[1] + i[2] or i[0] % 2 != (i[1] + i[2]) % 2:
        print('No')
        exit()
print('Yes')