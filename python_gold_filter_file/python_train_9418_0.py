def swap(c, r, t):
    c = list(c)
    c[r], c[t] = c[t], c[r]
    return ''.join(c)


k = -1
j = -1
n = input()
for i in range(len(n)):
    k = i
    if int(n[i]) % 2 == 0:
        j = i
        if n[i] < n[len(n)-1]:
            print(swap(n, i, len(n)-1))
            break

if k == len(n)-1 and j != -1:
    print(swap(n, j, k))
elif k == len(n)-1 and j == -1:
    print(-1)