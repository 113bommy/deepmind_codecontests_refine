N = int(input())
s = input()

for bit in range(4):
    animal = [-1] * N
    animal[0] = bit % 2
    animal[1] = bit // 2
    for i in range(1, N-1):
        if (animal[i] == 0) ^ (s[i] == 'o'):
            animal[i+1] = 1 - animal[i-1]
        else:
            animal[i+1] = animal[i-1]
    ok = True
    if animal[-1] == 0:
        if (s[-1] == 'o') ^ (animal[-2] == animal[0]):
            ok = False
    if animal[-1] == 1:
        if (s[-1] == 'o') ^ (animal[-2] != animal[0]):
            ok = False
    if animal[0] == 0:
        if (s[0] == 'o') ^ (animal[-1] == animal[1]):
            ok = False
    if animal[0] == 1:
        if (s[0] == 'o') ^ (animal[-1] != animal[1]):
            ok = False
    if ok:
        ans = ''
        for i in range(N):
            ans += 'S' if animal[i] == 0 else 'W'
        print(ans)
        exit()
print(-1)
